/********************************************************************
 * Ejercicio: Puzzle                                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/09              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Yesid Lázaro                                       *
 * Fecha: 22-09-2015                                                *
 * Comentarios: En esta solución, al hablar de "lineas" se incluyen *
 *  indistintamente filas o columnas.                               *
 *******************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;


map<int, int > variables_linea;
map<string, vector<pair<int, int> > > posiciones_variable;
map<string, int> valor_variable;
set<string> conteo_lineas;
bool lineas_analizadas[203];
int resultados[203];
int descubiertos;
string matriz_variables[101][101];

void leerDatos(int filas, int columnas);
void resolver(int linea, int filas, int columnas);
int buscarColumna(int filas, int columnas);
void reajustarIncognitas(string variable, int filas);
void imprimir();


int main(){
    int filas, columnas;
    while(cin >> filas >> columnas){
        descubiertos = 0;
        leerDatos(filas, columnas);
        buscarColumna(filas, columnas);
    }
    return 0;
}


void leerDatos(int filas, int columnas){
    variables_linea.clear();
    posiciones_variable.clear();
    valor_variable.clear();
    int i,j,k;
    string aux;
    for(i = 0; i < filas; i++){
        conteo_lineas.clear();
        for(j = 0; j < columnas; j++){
            cin >> aux;
            posiciones_variable[aux].push_back(make_pair(i,j));
            valor_variable[aux] = -1000000000;
            conteo_lineas.insert(aux);
            matriz_variables[i][j] = aux;

        }
        variables_linea[i] = conteo_lineas.size();
        cin >> resultados[i];
        lineas_analizadas[i] = false;
    }
    for( ;i < filas+columnas; i++){
        cin >> resultados[i];
        lineas_analizadas[i] = false;
    }
    for(j = 0, i = filas; j < columnas; j++,i++){
        conteo_lineas.clear();
        for(k = 0; k < filas; k++){
            conteo_lineas.insert(matriz_variables[k][j]);
        }
        variables_linea[i] = conteo_lineas.size();
    }

}
void resolver(int linea, int filas, int columnas){
    string aux, incognita;
    int acum=0, no_incognitas=0;
    if(linea<filas){
        for(int i = 0; i < columnas; i++){
            aux = matriz_variables[linea][i];
            if(valor_variable[aux] == -1000000000){
                incognita = aux;
                no_incognitas++;
            }else{
                acum += valor_variable[aux];
            }
        }

    }else{
        for(int i = 0; i < filas; i++){
            aux = matriz_variables[i][linea-filas];
            if(valor_variable[aux] == -1000000000){
                incognita = aux;
                no_incognitas++;
            }else{
                acum += valor_variable[aux];
            }
        }
    }
    acum = resultados[linea]-acum;

    acum /= no_incognitas;
    valor_variable[incognita] = acum;
    descubiertos++;
    reajustarIncognitas(incognita, filas);
    if(descubiertos<valor_variable.size()){
        buscarColumna(filas, columnas);
    }else{
        imprimir();
    }
}

int buscarColumna(int filas, int columnas){
    for(map<int, int>::iterator it = variables_linea.begin(); it != variables_linea.end(); ++it){
        if(!lineas_analizadas[it->first] && it->second == 1){
            lineas_analizadas[it->first] = true;
            resolver(it->first, filas, columnas);
            break;
        }
    }
}

void reajustarIncognitas(string variable, int filas){
    map<int,int> filas_temporal, columnas_temporal;
    for(int i=0; i < posiciones_variable[variable].size(); i++){
        filas_temporal[posiciones_variable[variable][i].first]++;
        columnas_temporal[posiciones_variable[variable][i].second]++;
        if(filas_temporal[posiciones_variable[variable][i].first] == 1){
            variables_linea[posiciones_variable[variable][i].first]--;
        }
        if(columnas_temporal[posiciones_variable[variable][i].second] == 1){
            variables_linea[posiciones_variable[variable][i].second+filas]--;
        }
    }
}

void imprimir(){
    for(map<string, int>::iterator it = valor_variable.begin(); it != valor_variable.end(); ++it){
        cout << it->first << " " << it->second << "\n";
    }
}

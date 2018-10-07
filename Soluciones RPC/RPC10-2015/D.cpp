/********************************************************************
 * Ejercicio: Directo a la felicidad                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/10              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 26-09-2015                                                *
 *******************************************************************/


#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

bool ady[1003][1003];
bool lista_ciudades[1003];
int ciudades;
int rutas;
int valor_ruta;
int valor_estadio;
int costo = 0;
int num_nodos;
int num_arcos;
queue<int> restantes;


void bfs(int i){
	if(!lista_ciudades[i]){
		num_nodos++;
		lista_ciudades[i] = true;
		for(int j = 0; j < ciudades; j++){
			if(ady[i][j]){
				num_arcos++;
				restantes.push(j);
			}
		}
	}
	if(!restantes.empty()){
		int aux = restantes.front();
		restantes.pop();
		bfs(aux);
	}else{
		num_arcos /= 2;
	}
}


void resolver(){
	int sum_rutas, sum_estadios;
	for(int i = 0; i < ciudades; i++){
		if(!lista_ciudades[i]){
			num_nodos = num_arcos = 0;
			bfs(i);
			sum_estadios = num_nodos * valor_estadio;
			sum_rutas = ( num_nodos * (num_nodos - 1) ) / 2;
			sum_rutas = (sum_rutas - num_arcos ) * valor_ruta;
			costo += min(sum_rutas, sum_estadios);
		}
	}
}


int main() {
	scanf("%d %d %d %d", &ciudades, &rutas, &valor_ruta, &valor_estadio);
	int aux1, aux2;
	for(int i = 0; i < rutas; i++){
		scanf("%d %d", &aux1, &aux2);
		ady[aux1 - 1][aux2 - 1] = true;
		ady[aux2 - 1][aux1 - 1] = true;
	}
	resolver();
	printf("%d\n", costo);
	return 0;
}

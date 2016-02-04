/********************************************************************
 * Ejercicio: Greg and Array                                        *
 * Url: http://codeforces.com/problemset/problem/295/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
 
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int i;
    long long n,m,k;
    cin >> n >> m >> k;
    long long valores[n];
    for(i = 0; i < n; i++){
        cin >> valores[i];
    }
    
    long long consultas[m][3];
    for(i = 0; i < m; i++){
        cin >> consultas[i][0] >> consultas[i][1] >> consultas[i][2];
        consultas[i][0]--;
        consultas[i][1]--;
    }
    
    long long veces[m];
    long long x,y;
    memset(veces, 0, sizeof(veces));
    for(i = 0; i < k; i++){
        cin >> x >> y;
        veces[x - 1]++;
        if(y < m){
            veces[y]--;
        }
    }
    for(i = 1; i < m; i++){
        veces[i] += veces[i-1];
    }
    for(i = 0; i < m; i++){
        consultas[i][2] *= veces[i];
    }
    
    
    long long sumas[n];
    memset(sumas, 0, sizeof(sumas));
    for(i = 0; i < m; i++){
        sumas[consultas[i][0]] += consultas[i][2];
        
        if(consultas[i][1] + 1 < n){
            sumas[consultas[i][1] + 1] -= consultas[i][2];
        }
    }

    for(i = 0; i < n; i++){
        if(i > 0){
            sumas[i] += sumas[i - 1];
        }
        cout << valores[i] + sumas[i];
        if(i + 1 != n){
            cout << " ";
        }else{
            cout << "\n";
        }
    }
    return 0;
}


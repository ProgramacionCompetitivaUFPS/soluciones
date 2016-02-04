/********************************************************************
 * Ejercicio: Bear and Blocks                                       *
 * Url: http://codeforces.com/problemset/problem/573/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <algorithm>

using namespace std;


int torres[100005], izq[100005], der[100005];

int main() { 
	int n,aux, rta = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
    	scanf("%d", &torres[i]);
    }
    for (int i = 0; i < n; i++){
    	if(i == 0){
    		izq[0] = 1;
    	}else{
    		izq[i] = min(izq[i - 1] + 1, torres[i]);
    	}
    }
    for (int i = n - 1; i >= 0; i--){
    	if(i == n - 1){
    		der[n - 1] = 1;
    	}else{
    		der[i] = min(der[i + 1] + 1, torres[i]);
    	}
    }
    
    for (int i = 0; i < n; i++){
    	aux = min(izq[i], der[i]);
    	rta = max(rta, aux);
    }
    printf("%d\n", rta);
    return 0;
}

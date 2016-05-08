/********************************************************************
 * Ejercicio:  E - Smooth Factor			                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 07-05-2016                                                *
 *******************************************************************/

#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int vals[100005];

int metodo(int n) {
	int cant = 1;
	vector<int> acum;
	for(int i = 1; i < n; i++) {
		if(vals[i] >= vals[i - 1]) {
			cant++;
		}else{
			acum.push_back(cant);
			cant = 1;
		}
	}
	acum.push_back(cant);
	int max = 0;
	if(acum.size() == 1){
		return acum[0];
	}else{
		for(int i = 1; i < acum.size(); i++) {
			if(acum[i] + acum[i - 1] > max){
				max = acum[i] + acum[i - 1];
			}
		}
		return max;
	}
	
}
	

int main() {
	int n;
	
	while(scanf("%d", &n) == 1 ) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &vals[i]);
		}
		printf("%d\n", metodo(n));
	}
	return 0;
}
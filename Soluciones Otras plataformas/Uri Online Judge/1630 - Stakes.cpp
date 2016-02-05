/********************************************************************
 * Ejercicio: Stakes                                                *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1630
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <algorithm>
using namespace std;

int mcd(int a, int b) {
	int aux;
	while(b!=0){
		a %= b;
		aux = b;
		b = a;
		a = aux;
	}
	return a;
}

int main() {
	int i,j,mi;
	while(scanf("%d %d", &i, &j) == 2){
		if(i == j){
			printf("%d\n", 4 );
		}else{
			mi = mcd(i,j);
			printf("%d\n", ((2 * i) + (2 * j)) / mi );
		}
	}
	return 0;
}

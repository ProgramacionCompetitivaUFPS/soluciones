/********************************************************************
 * Ejercicio:  A - Time Travel                                      *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 10-09-2016                                                *
 *******************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) == 3) {

		if(a == b || b == c || a == c) {
			printf("S\n");
		} else if(a + b == c || a + c == b || b + c == a) {
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}
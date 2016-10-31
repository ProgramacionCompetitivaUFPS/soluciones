/********************************************************************
 * Ejercicio:  I - Isosceles                                        *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 10-09-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;

int vals[50001];
int acumizq[50001];
int acumder[50001];

int main() {
	int t, i, rta = 0;
	while(scanf("%d", &t) == 1) {
		for(i = 0; i < t; i++) {
			scanf("%d", &vals[i]);
		}
		acumizq[0] = 1;
		for(i = 1; i < t; i++) {
			acumizq[i] = min(vals[i], acumizq[i - 1] + 1);
		}
		acumder[t - 1] = 1;
		for(i = t - 2; i >= 0; i--) {
			acumder[i] = min(vals[i], acumder[i + 1] + 1);
		}
		rta = 0;
		for(i = 0; i < t; i++) {
			rta = max(rta, min(acumder[i], acumizq[i]));
		}
		printf("%d\n", rta);
	}
	return 0;
}
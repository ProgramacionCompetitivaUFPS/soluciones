/********************************************************************
 * Ejercicio:  D - Divisors                                         *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 10-09-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c, d, m;
	
	while(scanf("%lld %lld %lld %lld", &a, &b, &c, &d) == 4) {
		stack<int> falt;
		if(b == 1) {
			printf("-1\n");
			goto salida;
		}
		
		for(long long n = 1; n * n <= c; n++) {
			if(c % n == 0) {
				if(n % a == 0 && n % b != 0 && d % n != 0) {
					printf("%lld\n", n);
					goto salida;
				}
				falt.push(c/n);
				
			}
		}
		while(!falt.empty()) {
			m = falt.top();
			falt.pop();
			if(m % a == 0 && m % b != 0 && d % m != 0) {
				printf("%lld\n", m);
				goto salida;
			}
		}
		printf("-1\n");
		salida:
		a = 0;
	}
	return 0;
}
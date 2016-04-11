/********************************************************************
 * Ejercicio:  D Standard Deviation			                        *
 * Url: https://acm.javeriana.edu.co/maratones/2016/03/             *
 * Lenguaje: c++                                                    *
 * Autor: MOV AX 4c00h (Melissa Delgado-Daniel Vega-Gerson Lázaro   * 
 * Fecha: 09-04-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

long long memo[1000006];

void resolver() {
	memo[0] = 0;
	memo[1] = 2;
	memo[2] = 8;
	for(long long i = 3; i <= 1000005; i++) {
		memo[i] = (i * i * 2) + memo[i - 2]; 
	}
}


int main() {
	int n;
	resolver();
	long long i;
	double rta;
	scanf("%d", &n);
	while(n != 0){
		rta = (double)memo[n - 1] / (double)(n - 1);
		
		printf("%.6lf\n", sqrt(rta));
		scanf("%d", &n);
	}
	return 0;
}
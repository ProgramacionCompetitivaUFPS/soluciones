/********************************************************************
 * Ejercicio:  G Tobby and the line game		                    *
 * Url: https://acm.javeriana.edu.co/maratones/2016/03/             *
 * Lenguaje: c++                                                    *
 * Autor: MOV AX 4c00h (Melissa Delgado-Daniel Vega-Gerson Lázaro   * 
 * Fecha: 09-04-2016                                                *
 *******************************************************************/

#include <cstdio>
using namespace std;


int main() {
	long double rta, di = 6;
	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4){
		rta = ((a - c) * (a - c)) + ((b - d) * (b - d)); 
		printf("%.6LF\n", rta / di);
	}
	return 0;
}
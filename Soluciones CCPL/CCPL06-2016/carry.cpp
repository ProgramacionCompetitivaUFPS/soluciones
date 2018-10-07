/********************************************************************
 * Ejercicio:  D - To Carry or Not to Carry	                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 04-06-2016                                                *
 *******************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	long a, b;
	while(scanf("%lld %lld", &a, &b) == 2) {
		cout << (a ^ b) << endl;
	}
	
	return 0;
}
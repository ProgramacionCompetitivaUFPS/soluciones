/********************************************************************
 * Ejercicio: Counting trapezoids        			                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/04              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 09-05-2015                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
	long long x, aumentador, triangular, rta,razon;
	while(cin>>x){
		triangular=1;
		aumentador = 2;
		rta = 0;
		while(x-triangular>=aumentador){
			if((x-triangular)%aumentador==0){
				rta++;
			}
			triangular+= aumentador;
			aumentador++;
		}
		cout << rta << "\n";
	}
	return 0;
}
/********************************************************************
 * Ejercicio: C                                    					*
 * Url: https://acm.javeriana.edu.co/maratones/2015/14	            *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 28-11-2015                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
	string frase;
	string per = "PER";
	cin >> frase;
	int rta = 0;
	for(int i = 0; i < frase.size(); i++){
		if(frase[i] != per[i % 3]){
			rta++;
		}
	}
	cout << rta << "\n";
	return 0;
}
/********************************************************************
 * Ejercicio: J                                    					*
 * Url: https://acm.javeriana.edu.co/maratones/2015/14	            *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 28-11-2015                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	
	string frase;
	getline(cin, frase);
	while(num > 0){
		getline(cin, frase);
		if(frase.substr(0,11) == "Simon says "){
			cout << frase.substr(10) << "\n";
		}
		num--;
	}
	return 0;
}
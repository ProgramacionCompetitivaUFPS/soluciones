/********************************************************************
 * Ejercicio: I                                    					*
 * Url: https://acm.javeriana.edu.co/maratones/2015/14	            *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 28-11-2015                                                *
 *******************************************************************/

#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int indices[100];

int main() {
	int casos, i, j;
	double raiz;
	cin >> casos;
	string frase,rta;
	while(casos > 0){
		cin >> frase;
		rta = "";
		raiz = ceil(sqrt(frase.size()));
		for(i = raiz-1, j = 0; i >= 0; i--, j++){
			indices[i] = (j * raiz);
		}
		j = 0;
		for(i = 0; i < raiz * raiz; i++){
			if(indices[j] < frase.size()){
				rta += frase[indices[j]];
			}
			indices[j]++;
			j = (j + 1) % (int)raiz;
		}
		cout << rta << "\n";
		casos--;
	}
	return 0;
}
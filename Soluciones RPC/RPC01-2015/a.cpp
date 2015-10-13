/********************************************************************
 * Ejercicio: Algebraic Teamwork 	                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/01              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2015                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
	long long valor[100001];
	int i=0;
	valor[0] = 0;
	valor[1] = 1;
	for(i=2;i<100001;i++){
		valor[i] = valor[i-1]*i; 
		if(valor[i]>=1000000007){
			valor[i]%=1000000007;
		}
	}
	int valores, casos;
	cin >> casos;
	while(casos>0){
		cin >> valores;
		cout << valor[valores]-1 << "\n";
		casos--;
	}
	return 0;
}
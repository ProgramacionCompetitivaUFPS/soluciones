/********************************************************************
 * Ejercicio:  C - Tennis Championship		                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 27-02-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned long long numberOfPlayers;
	unsigned long long number;
	unsigned long long matches;
	
	while(cin>>numberOfPlayers){
		matches = 0;
		number = numberOfPlayers;
		while(number>1){
			matches += number/2;
			number = number%2 + number/2;
			
		}
		cout<<matches<<"\n";
	
	}
	return 0;
}
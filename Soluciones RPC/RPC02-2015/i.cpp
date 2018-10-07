/********************************************************************
 * Ejercicio: Tractor				                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/02              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-03-2015                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
	long long casos,a,b,aumentador,rta;
	cin>> casos;
	while(casos>0){
		aumentador = 1;
		rta=0;
		cin >> a >> b;
		a++;b++;
		while(aumentador<=a || aumentador<=b){
			if(aumentador<=a && aumentador<=b){
				rta+=aumentador;
			}else if(aumentador<=a){
				rta+= b;
			}else if(aumentador<=b){
				rta+= a;
			}
			aumentador*=2;
		}
		while(a+b>=aumentador){
			rta+=a+b-aumentador;
			aumentador*=2;
		}
		cout << rta << "\n";
		casos--;
	}
	
	
	return 0;
}
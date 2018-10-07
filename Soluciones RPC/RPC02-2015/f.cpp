/********************************************************************
 * Ejercicio: Mixed Fractions 		                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/02              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-03-2015                                                *
 *******************************************************************/

#include <iostream>
#include <string.h>
#define endl "\n"
using namespace std;

int main() {
	long long x,y;
	cin>>x>>y;
	while(x!=0 && y!=0){
		cout<<(x/y)<<" ";
		cout<<(x%y)<<" / "<<y<<endl;
		cin>>x>>y;
	}
	return 0;
}
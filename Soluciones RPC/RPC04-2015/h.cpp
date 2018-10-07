/********************************************************************
 * Ejercicio: Hiding Sequence	         			                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/04              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 09-05-2015                                                *
 *******************************************************************/

#include <map>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int,int> mapa;
	int vec[n],valor, acum=0, aux, aux2;
	mapa[acum]++;
	for(int i=0;i<n;i++){
		cin >> valor;
		acum+=valor;
		mapa[acum]++;
	}
	
	aux=0;
	aux2=0;
	map<int,int>::iterator it;
	for(it=mapa.begin(); it!=mapa.end(); ++it){
		aux=it->second;
		aux2+=(aux*(aux-1))/2;
	}
	cout<<aux2<<"\n";
	return 0;
}
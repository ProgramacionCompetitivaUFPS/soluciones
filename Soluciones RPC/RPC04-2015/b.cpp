/********************************************************************
 * Ejercicio: Building Lost                                         *
 * Url: https://acm.javeriana.edu.co/maratones/2015/04              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 09-05-2015                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	unsigned long long i, n, sum, aux, triangular;
	string t;
	cin>>tc;
	while(tc>0){
		cin>>n;
		sum=0;
		for(i=1; i<n; i++){
			cin>>aux;
			if(aux!=i){
				getline(cin,t);
				break;
			}
		}
		
		cout<<i<<"\n";
		
		tc--;
	}
	return 0;
}
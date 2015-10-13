/********************************************************************
 * Ejercicio: Flexible Spaces 		                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/02              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-03-2015                                                *
 *******************************************************************/

#include <iostream>
#include <set>
#define endl "\n"
using namespace std;

int main() {
	int n, divisiones;
	cin>>n>>divisiones;
	int result[divisiones+1];
	result[0]=0;
	int i,j, aux;
	set<int> rta;
	for(i=1; i<=divisiones; i++){
		cin>>aux;
		result[i]=aux;
		rta.insert(n-aux);
		for(j=0; j<i; j++){
			rta.insert(aux-result[j]);
		}
	}
	set<int>::iterator it;
	for(it=rta.begin(); it!=rta.end(); it++){
		cout<<*it<<" ";
	}
	cout<<n;
	cout<<endl;
	return 0;
}
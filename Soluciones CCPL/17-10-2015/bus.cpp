/********************************************************************
 * Ejercicio: Bus                                                   *
 * Url: http://coj.uci.cu/24h/problem.xhtml?pid=3013&lang=es        *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Gerson Lázaro - Melissa Delgado -    *
 * Cristhian León)                                                  *
 * Fecha: 17-10-2015                                                *
 *******************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int tc, n;
	long long x;
	cin>>tc;
	while(tc>0){
		cin>>n;
		x=pow(2,n);
		cout<<x-1<<"\n";
		tc--;
	}
	return 0;
}

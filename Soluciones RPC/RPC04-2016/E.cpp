/********************************************************************
 * Ejercicio: E 					                                *
 * Url: hhttps://acm.javeriana.edu.co/maratones/2016/04/	        *
 * Lenguaje: c++                                                    *
 * Autor: Pied Piper (Melissa Delgado - Daniel Vega - Gerson Lázaro)*                                                    *
 * Fecha: 30-04-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int q, a ,b, k;
	
	while(cin>>s){
		cin>>q;
		while(q>0){
			cin>>a>>b;
			k=a+b-2;
			cout<<s[k%s.size()]<<"\n";
			q--;
		}
		
	}
	return 0;
}
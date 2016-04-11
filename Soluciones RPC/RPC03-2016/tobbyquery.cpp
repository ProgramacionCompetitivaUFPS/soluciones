/********************************************************************
 * Ejercicio:  C Tobby and Query			                        *
 * Url: https://acm.javeriana.edu.co/maratones/2016/03/             *
 * Lenguaje: c++                                                    *
 * Autor: MOV AX 4c00h (Melissa Delgado-Daniel Vega-Gerson Lázaro   * 
 * Fecha: 09-04-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, i, num, k, q, rta, l, r;
	int values [10][100010];
	
	while(cin>>n){
		
		for(k=0; k<10; k++){
			values[k][0]=0;
		}
		
		for(i=1; i<=n; i++){
			cin>>num;
			for(k=0; k<10; k++){
				values[k][i]=values[k][i-1];
				if(k==num){
					values[k][i]++;
				}
			}
		}
		
		cin>>q;
		while(q>0){
			cin>>l>>r;
			rta=0;
			for(k=0; k<10; k++){
				if(values[k][r]-values[k][l-1]>0){
					rta++;
				}
			}
			cout<<rta<<"\n";
			q--;
		}
		
	}
	return 0;
}
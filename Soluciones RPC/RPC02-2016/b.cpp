/**********************************************************************
 * Ejercicio:  B Eight Pointed Star			                       	  *
 * Url: https://acm.javeriana.edu.co/maratones/2016/02/               *
 * Lenguaje: c++                                                      *
 * Autor: sort(my_life)(Melissa Delgado - Daniel Vega - Gerson Lázaro *                                                   *
 * Fecha: 12-03-2016                                                  *
 *********************************************************************/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, i, k, j;
	
	int x, y, cont;
	int a,b,c;
	string s, rta;
	string mitad[2*27];
	
	while(cin>>n){
		k=(4*n)+1;
		j=0;
		
		s="";
		for(i=0; i<n; i++){
			s+=" ";
		}
		
		x=n;
		y=n-1;
		cont=0;
		a=1;
		b=n-2;
		c=1;
		
		while(j<(2*n)){
			if(j==0){
				rta=s+"*";
				for(i=0; i<x+y; i++){
					rta+=" ";
				}
				rta+="*";
				mitad[j]=rta;
				x--;
				y--;
			}
			else if(j<n){
				rta=s+"*";
				for(i=0; i<cont; i++){
					rta+=" ";
				}
				rta+="*";
				for(i=0; i<x+y; i++){
					rta+=" ";
				}
				
				rta+="*";
				for(i=0; i<cont; i++){
					rta+=" ";
				}
				rta+="*";
				
				x--;
				y--;
				cont++;
				mitad[j]=rta;
			}
			else if(j==n){
				rta="";
				for(i=0; i<k; i++){
					rta+="*";
				}
				mitad[j]=rta;
			}
			else if(j>n){
				rta="";
				for(i=0; i<a; i++){
					rta+=" ";
				}
				rta+="*";
				for(i=0; i<b; i++){
					rta+=" ";
				}
				rta+="*";
				for(i=0; i<b; i++){
					rta+=" ";
				}
				rta+="*";
				
				for(i=0; i<c; i++){
					rta+=" ";
				}
				rta+="*";
				for(i=0; i<b; i++){
					rta+=" ";
				}
				rta+="*";
				for(i=0; i<b; i++){
					rta+=" ";
				}
				rta+="*";
				
				mitad[j]=rta;
				a++;
				b--;
				c+=2;
			}
			cout<<mitad[j]<<endl;
			j++;
		}
		
		rta=s+"*"+s;
		for(i=0; i<n-1; i++){
			rta+=" ";
		}
		rta+="*";
		
		cout<<rta<<endl;
		
		for(i=(2*n)-1; i>=0; i--){
			cout<<mitad[i]<<endl;
		}
	}
	return 0;
}
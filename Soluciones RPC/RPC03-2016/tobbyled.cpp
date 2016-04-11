/********************************************************************
 * Ejercicio:  E Tobby and the LED display	                        *
 * Url: https://acm.javeriana.edu.co/maratones/2016/03/             *
 * Lenguaje: c++                                                    *
 * Autor: MOV AX 4c00h (Melissa Delgado-Daniel Vega-Gerson Lázaro   * 
 * Fecha: 09-04-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,t,i,j,k;
	long long w;
	char d, aux;
	char led[50010];
	char pantalla[50010];
	string rayita;
	
	while(cin>>n){
		cin>>w>>d;
		cin>>rayita;
		memset(led, ' ', sizeof(led));
		memset(pantalla, ' ', sizeof(pantalla));
		
		getline(cin, rayita);
		getline(cin, rayita);
		
		j=0;
		for(i=1; i<(2*n)+1; i+=2){
			led[j]=rayita[i];
			j++;
		}
		
		cin>>rayita;
		t=w%n;
		for(i=0; i<n; i++){
			if(d=='R'){
				j=(i+t)%n;
			}else{
				j=i-t;
				j=(j<0)?(n+j):j;
			}
			pantalla[j]=led[i];
		}
		
		cout<<rayita<<"\n";
		for(i=0; i<n; i++){
			cout<<"|"<<pantalla[i];
		}
		cout<<"|\n"<<rayita<<"\n";
	}
	return 0;
}
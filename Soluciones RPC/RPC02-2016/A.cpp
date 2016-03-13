/**********************************************************************
 * Ejercicio:  A 	Eating Chips 			                       	  *
 * Url: https://acm.javeriana.edu.co/maratones/2016/02/               *
 * Lenguaje: c++                                                      *
 * Autor: sort(my_life)(Melissa Delgado - Daniel Vega - Gerson Lázaro *                                                   *
 * Fecha: 12-03-2016                                                  *
 *********************************************************************/

#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,b,t, tb, tt, cantb, cantt;
	bool flagb;
	
	while(cin>>n){
		cin>>b>>t;
		cantb=cantt=0;
		tb=tt=0;
		while(n>0){
			flagb=false;
			if(tb==0){
				flagb=true;
				tb=min(b, n);
				cantb+=tb;
				n-=min(b, n);
				if(tt!=0){
					tt--;
					goto op;
				}
			}
			
			if(tt==0){
				tt=min(t, n);
				n-=min(t, n);	
				cantt+=tt;
				if(!flagb && tb!=0){
					tb--;
				}
			}
			
			op:
				if(tb>tt){
					tb-=tt;
					tt=0;
				}else if(tb<tt){
					tt-=tb;
					tb=0;
				}else{
					tb=tt=0;
				}
		}
		
		cout<<cantb<<" "<<cantt<<endl;
		
	}
	return 0;
}
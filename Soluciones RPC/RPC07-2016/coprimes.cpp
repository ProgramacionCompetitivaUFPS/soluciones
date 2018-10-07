/********************************************************************
 * Ejercicio:  L -  Lottery Coprimes                                *
 * Lenguaje: c++                                                    *
 * Autor: Elizabeth Ramirez                                         *
 * Fecha: 08-08-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;
int mcd(int a, int b) {
	int aux;
	while(b!=0){
		a %= b;
		aux = b;
		b = a;
		a = aux;
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t,x=0,y=0,d,s;
	cin>>t;
	for(int i=1;i<=t;i++){
		x=0,d=1,y=0;
		string rta="Not relative";
		bool veri=false;
		cin>>s;
		cout<<"Ticket #"<<i<<":\n";
		while(s>d){
			d*=10;
		}
		d/=10;
		while(d>1&&!veri){
			x=s/d;
			y=s%d;
			d/=10;
			if(mcd(x,y)==1){
				cout<<x<<" "<<y<<"\n";
				veri=true;
			}
		}
		if(!veri)cout<<"Not relative\n";
		
	}
	
}

/********************************************************************
 * Ejercicio:  K - How Sweet It Is!                                 *
 * Lenguaje: C++                                                    *
 * Autor: Elizabeth Ramirez                                         *
 * Fecha: 08-08-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,x,cont=0;
	string rta;
	cin>>n;
	while(n!=0){
		cont++;
		x+=n;
		rta=".";
		if(x>=50&&x<100){
			rta="Sweet!";
		}
		if(x>=100){
			rta="Totally Sweet!";
		}
		while(x>=50){
			x-=50;
		}
		if(rta!="."){
			cout<<"Input #"<<cont<<": "<<rta<<"\n";
		}	
		cin>>n;
	}


	return 0;
}


/****************************************************************************************************
 * Ejercicio: D as in Daedalus                                  									*
 * Url: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=702	*
 * Lenguaje: c++	                                              								  	*
 * Autor: Candelaria (Melissa Delgado - Cristhian León -  Gerson Lázaro)                          	*                        *
 * Fecha: 14-11-2015                                                								*
 ***************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,me,others,budget,gain, i ,j, aux;
	int cards[]={10000,1000,100,10,1};
	while(cin>>n){
		cin>>m;
		me=gain=0;
		for(i=0; i<m; i++){
			cin>>budget>>me;
			others=0;
			for(j=1; j<n; j++){
				cin>>aux;
				others+=aux;
			}
			if(budget>others){
				for(j=0; j<5; j++){
					if(others+cards[j]<=budget){
						gain+=cards[j];
						break;
					}
				}
				if(cards[j]>=me){
					gain-=me;
				}
			}
		}
		cout<<gain<<"\n";
	}
}
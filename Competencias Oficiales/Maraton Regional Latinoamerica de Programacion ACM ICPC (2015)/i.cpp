/****************************************************************************************************
 * Ejercicio: Identifying tea                                  										*
 * Url: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=702	*
 * Lenguaje: c++	                                              								  	*
 * Autor: Candelaria (Melissa Delgado - Cristhian León -  Gerson Lázaro)                          	*                        *
 * Fecha: 14-11-2015                                                								*
 ***************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, aux, i, rta;
	while(cin>>t){
		rta=0;
		for(i=0; i<5; i++){
			cin>>aux;
			if(aux==t){
				rta++;
			}
		}
		cout<<rta<<"\n";
	}
}
/********************************************************************
 * Ejercicio: The Price is Correct                                  *
 * Url: https://www.facebook.com/hackercup/problem/881509321917182/ *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 * Comentarios: A diferencia de ICPC, en Facebook Hackercup es      *
 *     posible leer y escribir entradas directamente en archivos de *
 *     texto. Por comodidad, se leen las entradas desde input.txt y *
 *     se escriben los resultados en output.txt                     *
 *******************************************************************/

#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

long long valores[100010];


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,t,n, act, pivot;
	long long p, rta, acum;
	scanf("%d", &t);
	for(i = 1; i <= t; i++){
		scanf("%d %lld", &n, &p);
		rta = 0;
		acum = 0;
		act = 0;
		pivot = 0;
		for(j = 0; j < n; j++){
			scanf("%lld", &valores[j]);
			if(valores[j] < p){
				acum += valores[j];
				act++;
				while(acum > p && act > 0){
					acum -= valores[pivot];
					pivot++;
					act--;
				}
				rta += act;
			}else if(valores[j] == p){
				acum = 0;
				act = 0;
				rta++;
			}else{
				acum = 0;
				act = 0;
			}	
		}
		printf("Case #%d: %lld\n", i, rta);
	}
  	return 0;
}

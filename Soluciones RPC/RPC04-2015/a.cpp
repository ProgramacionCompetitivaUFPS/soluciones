/********************************************************************
 * Ejercicio: Ambitious journey         			                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/04              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 09-05-2015                                                *
 *******************************************************************/

#include <stdio.h>
using namespace std;

int main(){
	int n, i, j;
	long long tiendas[1010][1010];
	long long dato, arriba, izq;
	scanf("%i", &n);
	while(n!=0){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				scanf("%i", &dato);
				tiendas[i][j]=dato;
				arriba=-1;
				izq=-1;
				if(i>0)
					arriba=tiendas[i-1][j];
				if(j>0)
					izq=tiendas[i][j-1];
				if(arriba>izq){
					tiendas[i][j]+=arriba;
				}else if(izq>arriba || (izq==arriba && izq!=-1)){
					tiendas[i][j]+=izq;
				}
			}
		}
		printf("%i\n",tiendas[n-1][n-1]);
		scanf("%i", &n);
	}
	return 0;
}
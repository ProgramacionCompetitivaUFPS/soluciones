/********************************************************************
 * Ejercicio: Milling machines	 	                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/08              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 08-08-2015                                                *
 *******************************************************************/

#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int w,s,x,y,i,j;
	scanf("%d %d", &w, &s);
	scanf("%d %d", &x, &y);
	
	int pieces [w][x];
	for(i=0; i<w; i++){
		for(j=0; j<x; j++){
			scanf("%d", &pieces[i][j]);
		}
	}
	
	int cuts[x];
	int aux;
	memset(cuts, 0, sizeof(cuts));
	
	j=0; 
	
	while(j<s){
		for(i=0; i<x; i++){
			scanf("%d", &aux);
			cuts[i]=max(aux, cuts[i]);
		}
		j++;
	}
	
	for(i=0; i<w; i++){
		for(j=0; j<x; j++){
			aux=min((y-cuts[j]), pieces[i][j]);
			printf("%d", aux);
			if(j<x-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
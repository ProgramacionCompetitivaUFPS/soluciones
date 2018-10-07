/********************************************************************
 * Ejercicio: Strategy Game	                                        *
 * Url: https://acm.javeriana.edu.co/maratones/2015/09              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 12-09-2015                                                *
 *******************************************************************/

#include <string.h>
#include <cstdio>
using namespace std;

int main() {
	int i,j,z,rta,aux,ind;
	while(scanf("%d %d\n", &i, &j)==2){
		int valores[i];
		memset(valores, 0, sizeof(valores));
		for(z=0;z<i*j;z++){
			scanf("%d\n", &aux);
			valores[z%i] += aux;
		}
		rta=0;
		ind =-1;
		for(z=0;z<i;z++){
			if(rta<=valores[z]){
				rta = valores[z];
				ind = z;
			}
		}
		printf("%d\n",ind+1);
	}
	return 0;
}
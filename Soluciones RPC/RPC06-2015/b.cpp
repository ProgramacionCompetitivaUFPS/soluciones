/********************************************************************
 * Ejercicio: Most					                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/06              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro )                                                  *
 *******************************************************************/

#include <cstdio>
#define endl "\n"

using namespace std;

int main(){
	int n, der, izq, minDer, maxIzq, minimo, dif, d, disD, disL, i;
	scanf("%d", &n);

	while(n>0){
		scanf("%d", &d);
		scanf("%d %d", &izq, &der);
		maxIzq=izq;
		minDer=der;

		disL=disD=0;
		minimo=minDer-maxIzq;
		i=1;

		while(i<d){
			scanf("%d %d", &izq, &der);
			disL++;
			disD++;

			if(izq>=maxIzq-disL){
				maxIzq=izq;
				disL=0;
			}

			if(der<=minDer+disD){
				minDer=der;
				disD=0;
			}

			dif=(der-maxIzq)+disL;
			if(minimo>dif)	minimo=dif;

			dif=(minDer-izq)+disD;
			if(minimo>dif)	minimo=dif;

			i++;
		}

		printf("K prechodu reky je treba %i pontonu.\n", minimo);
		n--;
	}
	return 0;
}
/********************************************************************
 * Ejercicio: Tri-du		                                        *
 * Url: https://acm.javeriana.edu.co/maratones/2015/09              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 12-09-2015                                                *
 *******************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int A,B;
	while(scanf("%d %d", &A, &B)==2){
		if(A==B){
			printf("%d\n", A);
		}else{
			printf("%d\n", max(A,B));
		}
	}
	return 0;
}
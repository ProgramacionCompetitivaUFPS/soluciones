/********************************************************************
 * Ejercicio: Factorial 	                                        *
 * Url: https://acm.javeriana.edu.co/maratones/2015/09              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 12-09-2015                                                *
 *******************************************************************/

#include <cstdio>
using namespace std;

int main() {
	int factorial[9]= {1,2,6,24,120,720,5040,40320,362880};
	int N,rta;
	while(scanf("%d", &N)==1){
		rta = 0;
		for(int i=8; N!=0;i--){
			if(N>=factorial[i]){
				rta++;
				N -= factorial[i];
				i++;
			}
			
		}
		printf("%d\n", rta);
	}
	
	
	return 0;
}
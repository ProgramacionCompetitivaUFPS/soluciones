/********************************************************************
 * Ejercicio: E Icelandic Motorclubs 	                  			*
 * Url: https://acm.javeriana.edu.co/maratones/2016/01/            	*
 * Lenguaje: c++	                                                *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -   	*
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2016                                              	*
 *******************************************************************/

#include <cstdio>
using namespace std;

int main() {
	int t, i, n, a, b, acum, ind, menor;
	scanf("%d", &t);
	while(t){
		acum = 0;
		menor = 99999999;
		ind = -1;
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			if(acum < menor){
				ind = i;
				menor = acum;
			}
			scanf("%d %d", &a, &b);
			acum += a - b;
		}
		if(acum >= 0){
			printf("%d\n", ind + 1);
		}else{
			printf("IMPOSSIBLE\n");
		}
		t--;
	}
	return 0;
}
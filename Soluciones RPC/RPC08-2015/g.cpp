/********************************************************************
 * Ejercicio: Extreme Sort		 	                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/08              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 08-08-2015                                                *
 *******************************************************************/

#include <cstdio>
using namespace std;

int main() {
	int N, ult, act;
	scanf("%d", &N);
	bool flag = true;
	scanf("%d", &ult);
	for(int i=1;i<N;i++){
		scanf("%d", &act);
		if(flag && act<ult){
			flag = false;
		}
		ult = act;
	}
	if(flag){
		printf("yes\n");
	}else{
		printf("no\n");
	}
	return 0;
}
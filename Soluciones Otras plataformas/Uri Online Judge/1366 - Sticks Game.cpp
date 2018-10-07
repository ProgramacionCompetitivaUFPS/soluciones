/********************************************************************
 * Ejercicio: Stick Game                                            *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1366
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
 
#include <cstdio>
using namespace std;

int main() {
	int i,n,a,b,rta;
	scanf("%d", &n);
	while(n != 0){
		rta = 0;
		for(i = 0; i < n; i++){
			scanf("%d %d", &a, &b);
			rta += (b / 2);
		}
		printf("%d\n", rta / 2);
		scanf("%d", &n);
	}
	return 0;
}

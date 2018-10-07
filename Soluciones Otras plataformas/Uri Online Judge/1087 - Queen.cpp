/********************************************************************
 * Ejercicio: Queen                                                 *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1087
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int a,b,c,d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	while(a != 0){
		if(a == c && b == d){
			printf("0\n");
		}else if(a == c || b == d){
			printf("1\n");
		}else if(a - c == b - d){
			printf("1\n");
		}else if(abs(a - c) == abs(b - d)){
			printf("1\n");
		}else{
			printf("2\n");
		}
		scanf("%d %d %d %d", &a, &b, &c, &d);
	}
	return 0;
}

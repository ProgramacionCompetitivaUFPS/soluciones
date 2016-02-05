/********************************************************************
 * Ejercicio: Perfect Number                                        *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1164
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
using namespace std;

int main() {
	int n,x,i,sum;
	while(scanf("%d", &n) == 1){
		while(n > 0){
			scanf("%d", &x);
			sum = 1;
			for(i = 2; i * i <= x; i++){
				if(x % i == 0){
					sum += (i + (x / i));
				}
				if(sum > x){
					break;
				}
			}
			if(sum == x && x != 1){
				printf("%d eh perfeito\n", x);	
			}else{
				printf("%d nao eh perfeito\n", x);
			}
			n--;
		}
	}
	
	return 0;
}

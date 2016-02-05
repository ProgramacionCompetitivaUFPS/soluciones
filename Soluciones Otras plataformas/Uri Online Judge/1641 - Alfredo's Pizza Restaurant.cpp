/********************************************************************
 * Ejercicio: Alfredo's Pizza Restaurant                            *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1371
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
using namespace std;

int main() {
	int r, i;
	double a, b;
	scanf("%d", &r);
	i = 1;
	while(r != 0){
		scanf("%lf %lf", &a, &b);
		a /= 2;
		b /= 2;
		if(a * a + b * b <= r * r){
			printf("Pizza %d fits on the table.\n", i);
		}else{
			printf("Pizza %d does not fit on the table.\n", i);	
		}
		
		scanf("%d", &r);
		i++;
	}
	return 0;
}

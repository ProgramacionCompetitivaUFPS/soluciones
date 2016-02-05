/********************************************************************
 * Ejercicio: Triangulo binomial, la venganza                       *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1807
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
using namespace std;

int binaryExponentiation(int a, int b, int c){
    if (b == 0){
    	return 1;
    } 
    if (b % 2 == 0){
        int temp = binaryExponentiation(a,b/2, c);
        return ((long long)(temp) * temp) % c;
    }else{
        int temp = binaryExponentiation(a, b-1, c);
        return ((long long)(temp) * a) % c;
    }
}

int main() {
	int c;
	scanf("%d", &c);
	printf("%d\n", binaryExponentiation(3, c, 2147483647));
	return 0;
}

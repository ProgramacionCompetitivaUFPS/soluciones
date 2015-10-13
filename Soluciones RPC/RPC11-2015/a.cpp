/********************************************************************
 * Ejercicio: Alcoholic Pilots                                      *
 * Url: https://acm.javeriana.edu.co/maratones/2015/11              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 10-10-2015                                                *
 *******************************************************************/

#include <cstdio>
using namespace std;
/*

Take me to church
nananananananana

*/
long long num = 0;
long long den = 0;

long long mcd(long long a, long long b) {
	long long aux;
	while(b!=0){
		a %= b;
		aux = b;
		b = a;
		a = aux;
	}
	return a;
}
long long mcm(long long a, long long b) {
	return a*b/mcd(a,b);
}
void simplificar(){
     long long dividir=mcd(num, den);
     num/=dividir;
     den/=dividir;
}


int main() {
	long long a,b,c,d;
	int caso = 1;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	while(a != 0){
		printf("Case #%d: ", caso);
		caso++;
		if((double)b/a < (double)d/c){
			printf("You owe me a beer!\n");
		}else{
			printf("No beer for the captain.\n");		
		}
		den = mcm(a,c);
		num = (den/a*b) + (den/c*d);
		den *= 2;
		simplificar();
		if(den == 1){
			printf("Avg. arrival time: %lld\n", num);
		}else{
			printf("Avg. arrival time: %lld/%lld\n",num, den);
		}
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	}
	
	return 0;
}
/********************************************************************
 * Ejercicio: Upside down primes  	                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/08              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 08-08-2015                                                *
 *******************************************************************/

#include <cstdio>
using namespace std;

bool isPrime(long long value){
	if(value < 2){
		return false;
	}
	if(value % 2 == 0 && value != 2){
		return false;
	}
	for(long long i = 3; i * i <= value; i += 2 ){
		if( value % i == 0){
			return false;
		}
	}
	return true;
}


int main() {
	long long value, reverse;
	int temp;
	scanf("%lld", &value);
	int invert[10] = {0,1,2,-1,-1,5,9,-1,8,6};
	bool flag = isPrime(value);
	if(flag){
		reverse = 0;
		while(value != 0){
			reverse *= 10;
			temp = invert[value % 10];
			if(temp != -1){
				reverse += temp;
				value /= 10;
			}else{
				flag = false;
				goto print;
			}
			
		}
		flag = isPrime(reverse);
	}
	
	if(flag){
		printf("yes\n");
	}else{
		print:
		printf("no\n");
	}
	return 0;
}
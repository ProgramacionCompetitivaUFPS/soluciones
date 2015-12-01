/********************************************************************
 * Ejercicio: Currency System in Geraldion                          *
 * Url: http://codeforces.com/problemset/problem/560/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/

#include <cstdio>
using namespace std;

int main() {
	int a,b,c;
	scanf("%d",&a);
	b=100000000;
	while(a>0){
		scanf("%d", &c);
		if(c<b){
			b = c;
		}
		a--;
	}
	if(b==1){
		printf("-1\n");
	}else{
		printf("1\n");
	}
	return 0;
}
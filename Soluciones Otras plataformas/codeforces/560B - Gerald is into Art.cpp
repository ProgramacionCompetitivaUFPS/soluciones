/********************************************************************
 * Ejercicio: Gerald is into Art                                    *
 * Url: http://codeforces.com/problemset/problem/560/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a1,a2,a3,b1,b2,b3;
	scanf("%d %d\n%d %d\n%d %d",&a1, &b1, &a2,&b2,&a3,&b3);
	if(((a2+a3<=a1)&&(max(b2,b3)<=b1)) || ((a2+a3<=b1)&&(max(b2,b3)<=a1))){
		printf("YES\n");
	}else if(((a2+b3<=a1)&&(max(b2,a3)<=b1)) || ((a2+b3<=b1)&&(max(b2,a3)<=a1))){
		printf("YES\n");
	}else if(((b2+a3<=a1)&&(max(a2,b3)<=b1)) || ((b2+a3<=b1)&&(max(a2,b3)<=a1))){
		printf("YES\n");
	}else if(((b2+b3<=a1)&&(max(a2,a3)<=b1)) || ((b2+b3<=b1)&&(max(a2,a3)<=a1))){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}
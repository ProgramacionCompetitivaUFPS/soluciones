/********************************************************************
 * Ejercicio: Sorting Railway Cars                                  *
 * Url: http://codeforces.com/problemset/problem/605/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <algorithm>
using namespace std;

int cars[100005];

int main(){
	int n, i, car, aux = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &car);
		cars[car] = cars[car - 1] + 1;
		aux = max(cars[car], aux);
	}
	aux = n - aux;
	printf("%d\n", aux);
	return 0;
}

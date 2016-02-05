/********************************************************************
 * Ejercicio: Close the doors!                                      *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1371
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	vector<int> vals;
	for(int i = 1; i * i <= 25000000; i++){
		vals.push_back(i * i);
	}
	int n, i;
	bool f;
	scanf("%d", &n);
	while(n != 0){
		f = false;
		for(i = 0; i < vals.size() && vals[i] <= n; i++){
			if(f){
				printf(" ");
			}
			f = true;
			printf("%d", vals[i]);
		}
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}

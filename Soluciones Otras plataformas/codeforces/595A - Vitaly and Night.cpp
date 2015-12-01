/********************************************************************
 * Ejercicio: Vitaly and Night                                      *
 * Url: http://codeforces.com/problemset/problem/595/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/


#include <cstdio>
using namespace std;

int main() {
	int i,n,m,rta = 0;
	scanf("%d %d", &n, &m);
	while(n > 0){
		int piso[2*m];
		for(i = 0; i < 2*m; i++){
			scanf("%d", &piso[i]);
		}
		for(i = 0; i < 2*m; i+=2){
			if(piso[i]==1 || piso[i+1]==1){
				rta++;
			}
		}
		n--;
	}
	printf("%d\n", rta);
	return 0;
}
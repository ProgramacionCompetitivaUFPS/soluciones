/********************************************************************
 * Ejercicio: Power Crisis                                          *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1031
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <cstring>
using namespace std;

bool arreglo[200];

int josefo(int n){
	if(n == 13){
		return 1;
	}
	bool flag;
	int i = 2, marcados = 0, k, l;
	while(true){
		memset(arreglo, false, sizeof(arreglo));
		arreglo[0] = true;
		marcados = 1;
		l = 0;
		flag = false;
		while(marcados < n){
			if(arreglo[12]){
				flag = true;
				break;
			}
			k = 0;
			while(k < i){
				l = (l + 1) % n;
				if(!arreglo[l]){
					k++;
				}
			}
			arreglo[l] = true;
			marcados++;
		}
		if(!flag){
			return i;
		}
		i++;
	}	
}


int main() {
	int n;
	scanf("%d", &n);
	while(n != 0){
		printf("%d\n", josefo(n));
		scanf("%d", &n);
	}
	return 0;
}

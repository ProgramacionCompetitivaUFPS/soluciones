/********************************************************************
 * Ejercicio: J -  Cacho			    	                        *
 * Lenguaje: c++                                          			*
 * Autor: UFPSTeamLeader (Gerson Lázaro - Melissa Delgado)          *
 * Fecha: 18-02-2017                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[5];
	bool flag;
	scanf("%d", &n);
	while(n-- > 0) {
		flag = true;
		scanf("%d", &a[0]);
		for(int i = 1; i < 5; i++) {
			scanf("%d", &a[i]);
			if(a[i - 1] + 1 != a[i]) {
				flag = false;
			}
		}
		if(flag) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}
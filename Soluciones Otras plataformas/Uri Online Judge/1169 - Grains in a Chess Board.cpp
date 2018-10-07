/********************************************************************
 * Ejercicio: Grains in a chess board                               *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1169
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
using namespace std;

long long granos[65];
long long kg[64];
long long g[64];


void llenar(){
	granos[0] = 1;
	for(int i = 1; i < 65; i++){
		granos[i] = granos[i - 1]*2;
		g[i] = g[i - 1]*2;
		kg[i] = kg[i - 1]*2;
		g[i] += granos[i] / 12;
		kg[i] += g[i] / 1000;
		granos[i] %= 12;
		g[i] %= 1000;
	}	
}


int main() {
	llenar();
	int casos, a;
	scanf("%d", &casos);
	while(casos > 0){
		scanf("%d", &a);
		printf("%lld kg\n", kg[a]);
		casos--;
	}
	return 0;
}

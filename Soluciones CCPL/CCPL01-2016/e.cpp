/********************************************************************
 * Ejercicio:  E - Going Shopping with Grandma (I)                  *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 27-02-2016                                                *
 *******************************************************************/

#include <cstdio>
using namespace std;


long long dp[1005][2010];
long long mod = 9999959999;

long long int ejecutardp(int a, int b){
	if(dp[a][b] != 0){
		return dp[a][b];
	}
	if(a == 0){
		dp[a][b] = b + 1;
		return b + 1;
	}
	if(b == 0){
		dp[a][b] = 1 + ejecutardp(a - 1, 1);
		return dp[a][b];
	}
	dp[a][b] = (1 + ejecutardp(a - 1, b + 1) + ejecutardp(a, b - 1)) % mod;
	return dp[a][b];
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	while(a > 0 || b > 0){
		ejecutardp(a, b);
		printf("%lld\n",dp[a][b]);
		scanf("%d %d", &a, &b);
	}
	return 0;
}
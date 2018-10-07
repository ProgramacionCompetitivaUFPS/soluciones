/********************************************************************
 * Ejercicio: Art Union                                             *
 * Url: http://codeforces.com/problemset/problem/416/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[50005][5];

int main() {
	int m, n, i, j, aux;
	scanf("%d %d", &m, &n);
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &aux);
			if(i == 0 && j == 0){
				dp[0][0] = aux;
			}else if(i == 0){
				dp[0][j] = dp[0][j-1] + aux;
			}else if(j == 0){
				dp[i][0] = dp[i-1][0] + aux;
			}else{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + aux;
			}
		}
		printf("%d", dp[i][n - 1]);
		if(i + 1 < m){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}

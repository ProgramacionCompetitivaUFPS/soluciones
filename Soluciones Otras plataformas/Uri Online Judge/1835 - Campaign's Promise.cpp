/********************************************************************
 * Ejercicio: Campaign's Promise                                    *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1835
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <cstring>
using namespace std;

int ady[105][105];
bool visitados[105];
int n, m;

void dfs(int i){
	visitados[i] = true;
	for(int j = 0; j < n; j++){
		if(ady[i][j] == 1 && !visitados[j]){
			dfs(j);
		}	
	}
}

int main() {
	int i, j, t = 0, aux1, aux2, rta;
	scanf("%d", &t);
	for ( i = 1; i <= t; i++){
		memset(visitados, false, sizeof(visitados));
		for(j = 0; j < 105; j++){
			memset(ady[j], 0, sizeof(ady[j]));
		}
		scanf("%d\n%d", &n, &m);
		for(j = 0; j < m; j++){
			scanf("%d %d", &aux1, &aux2);
			aux1--;aux2--;
			ady[aux1][aux2] = 1;
			ady[aux2][aux1] = 1;
		}
		rta = -1;
		for(j = 0; j < n; j++){
			if(!visitados[j]){
				dfs(j);
				rta++;
			}
		}
		if(rta == 0){
			printf("Caso #%d: a promessa foi cumprida\n", i);
		}else{
			printf("Caso #%d: ainda falta(m) %d estrada(s)\n", i, rta);
		}
		
	}
	return 0;
}
 

/********************************************************************
 * Ejercicio: Easy Problem from Rujia Liu?                          *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1424
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
 
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main() {
	int i,n,m, aux1, aux2;
	while(scanf("%d %d", &n, &m) == 2){
		map<int, vector<int> > mapa;
		for(i = 1; i <= n; i++){
			scanf("%d", &aux1);
			mapa[aux1].push_back(i);
		}
		for(i = 0; i < m; i++){
			scanf("%d %d", &aux1, &aux2);
			aux1--;
			auto search = mapa.find(aux2);
    		if(search != mapa.end() && mapa[aux2].size() > aux1){
    			printf("%d\n", mapa[aux2][aux1]);
    		}else{
    			printf("0\n");
    		}
		}
	}
	
	return 0;
}

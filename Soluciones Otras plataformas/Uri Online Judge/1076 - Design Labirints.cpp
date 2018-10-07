/********************************************************************
 * Ejercicio: Design Labirints                                      *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1076
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <map>
#include <vector>
#include <set>
using namespace std;

int n;
map<int, vector<int> > ady;
set<int> recorridos;
int total;

void dfs(int n){
	int a = recorridos.size();
	recorridos.insert(n);
	if(recorridos.size() != a){
		total++;
		for(int i = 0; i < ady[n].size(); i++){
			dfs(ady[n][i]);
		}
	}
}

int main() {
	int t, nodos, arcos, a, b;
	scanf("%d", &t);
	while(t > 0){
		ady.clear();
		scanf("%d", &n);
		scanf("%d %d", &nodos, &arcos);
		while(arcos > 0){
			scanf("%d %d", &a, &b);
			ady[a].push_back(b);
			ady[b].push_back(a);
			arcos--;
		}
		total = 0;
		recorridos.clear();
		dfs(n);
		printf("%d\n", (total - 1) * 2);
		t--;
	}
	return 0;
}

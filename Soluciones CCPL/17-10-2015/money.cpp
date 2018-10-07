/********************************************************************
 * Ejercicio: Money Matters                                         *
 * Url: https://uva.onlinejudge.org/external/116/p11690.pdf         *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Gerson Lázaro - Melissa Delgado -    *
 * Cristhian León)                                                  *
 * Fecha: 17-10-2015                                                *
 *******************************************************************/


#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


vector<int> ady[10005];
int money[10005];
int vis[10005];
int total, n, m;

void dfs(int src){
	int i, x;
	total+=money[src];
	vis[src]=1;
	for(i=0; i<ady[src].size(); i++){
		x=ady[src][i];
		if(vis[x]==0){
			dfs(x);
		}
	}
}

int init(){
	for(int i=0; i<n; i++){
		ady[i].clear();
		vis[i]=0;
	}
}

int main() {
	int tc, i, s, d;
	bool flag;
	cin>>tc;
	while(tc>0){
		cin>>n>>m;
		init();
		for(i=0; i<n; i++){
			cin>>money[i];
		}
		
		for(i=0; i<m; i++){
			cin>>s>>d;
			ady[s].push_back(d);
			ady[d].push_back(s);
		}
		
		flag=true;
		for(i=0; i<n; i++){
			if(vis[i]==0){
				total=0;
				dfs(i);
				if(total!=0){
					flag=false;
					cout<<"IMPOSSIBLE\n";
					break;
				}
			}
		}
		
		if(flag){
			cout<<"POSSIBLE\n";
		}
		tc--;
	}
	return 0;
}

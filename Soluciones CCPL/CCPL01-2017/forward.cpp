/********************************************************************
 * Ejercicio: F -  Forwarding Emails		                        *
 * Lenguaje: c++                                          			*
 * Autor: UFPSTeamLeader (Gerson Lázaro - Melissa Delgado)          *
 * Fecha: 18-02-2017                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int n, loopValue;
bool loop;
int ady[50010];
int r[50010], cant[50010], dfs_low[50010];

void init(){
	int i;
	for( i = 0; i <= n; i++ ){
		ady[i] = 0;
		r[i] = 0;
		cant[i] = 0;
		dfs_low[i] = 0;
	}
}

int dfs( int src, int recorrido, int cont ){
	r[src] = recorrido;
	int aux = 1;
	dfs_low[src] = cont;
	
	if( r[ ady[src] ] != 0 ){
		if( r[ ady[src] ] != recorrido ){
			cant[src] = cant[ ady[src] ] + 1;
			return cant[src];
		}else{ 
			loop = true;
			loopValue = ady[src];
			cant[src] = (cont + 1) - dfs_low[ ady[src] ];
			return cant[src];
		}
	}else{
		aux = dfs( ady[src], recorrido, cont+1 );
	}
	
	if( loop ){
		cant[src] = aux;
		if( src == loopValue ) loop = false;
	}else{
		cant[src] = aux + 1;
	}
	
	return cant[src];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int TC, tc, i, u, v, rta, maxv;
	cin >> TC;
	
	tc = 1;
	
	while( tc <= TC ){
		cin >> n;
		
		init();
		
		for( i = 0; i < n; i++){
			cin >> u >> v;
			ady[u] = v;
		} 
		
		maxv = 0;
		rta = 0;
		
		for( i = 1; i <= n; i++ ){
			if( r[i] == 0 ){
				loop = false;
				loopValue = -1;
				u = dfs( i, i, 1 );
				if( u > maxv ){
					rta = i;
					maxv = u;
				}
			}
		}
		
		cout << "Case " << tc << ": " << rta << "\n";
		tc++;	
	}
	
	
	return 0;
}
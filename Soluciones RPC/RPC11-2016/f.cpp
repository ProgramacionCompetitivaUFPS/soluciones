/********************************************************************
 * Ejercicio:  F - Fusing trees                                     *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 10-09-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int tree1 [10010][2];
int tree2 [10010][2];
int tic, tdc, rci, rcd;


void dfs1( int parent, int acum, bool isCenter){
	if(isCenter){
		rci++;
	}
	acum++;
	
	
	if( tree1[parent][0] != 0 ){
		dfs1( tree1[parent][0], acum, isCenter );
	}else{
		tic = max( tic, acum );
	}
	
	if( tree1[parent][1] != 0 ){
		dfs1( tree1[parent][1], 0, false);
	}
}

void dfs2( int parent, int acum, bool isCenter){
	if(isCenter){
		rcd++;
	}
	acum++;
	
	if( tree2[parent][0] != 0 ){
		dfs2( tree2[parent][0], acum, isCenter );
	}else{
		tdc = max( tdc, acum );
	}
	
	if( tree2[parent][1] != 0 ){
		dfs2( tree2[parent][1], 0, false);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int v1, v2, n, c, o, i;
	
	while( cin >> v1 ){
		tic = tdc = rci = rcd = 0;
		i = 0; 
		while( i < v1 ){
			cin >> n >> o >> c;
			tree1[n][0] = c;
			tree1[n][1] = o;
			i++;
		}
		
		cin >> v2;
		i = 0; 
		while( i < v2 ){
			cin >> n >> c >> o;
			tree2[n][0] = c;
			tree2[n][1] = o;
			i++;
		}
		
		dfs1(1, 0, true);
		dfs2(1, 0, true);
		
		n = max( min( rci, tdc ), min( rcd, tic ) );
		cout << (v1 + v2 - n) << "\n";
		
	}
	
	return 0;
}
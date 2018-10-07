/********************************************************************
 * Ejercicio: Contamination                                         *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1583
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <iostream>
#include <vector>
using namespace std;

string mapa[55];
int n,m;
vector<int> x,y;

void dfs(int xi, int yi){
	if(xi > 0 && mapa[xi - 1][yi] == 'A'){
		mapa[xi - 1][yi] = 'T';
		dfs(xi - 1, yi);
	}
	if(xi + 1 < n && mapa[xi + 1][yi] == 'A'){
		mapa[xi + 1][yi] = 'T';
		dfs(xi + 1, yi);
	}
	if(yi > 0 && mapa[xi][yi - 1] == 'A'){
		mapa[xi][yi - 1] = 'T';
		dfs(xi, yi - 1);
	}
	if(yi + 1 < m && mapa[xi][yi + 1] == 'A'){
		mapa[xi][yi + 1] = 'T';
		dfs(xi, yi + 1);
	}
}


void recorrer(){
	int j;
	for(int i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(mapa[i][j] == 'T'){
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	for(int i = 0; i < x.size(); i++){
		dfs(x[i], y[i]);
	}
}


int main() {
	int i;
	cin >> n >> m;
	while(n != 0 && m != 0){
		x.clear();
		y.clear();
		for(i = 0; i < n; i++){
			cin >> mapa[i];
		}
		recorrer();
		for(i = 0; i < n; i++){
			cout << mapa[i] << endl;
		}
		cout << endl;
		cin >> n >> m;	
	}
	return 0;
}

/********************************************************************
 * Ejercicio: Pocket Book                                           *
 * Url: http://codeforces.com/problemset/problem/152/C              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <iostream>
#include <set>
#include <string>
using namespace std;

string cadenas[105];
long long mod = 1000000007;

int main() {
	int i, j, n, m;
	long long rta = 1;
	set<int> aux;
	cin >> n >> m;
	for(i = 0; i < n; i++){
		cin >> cadenas[i];
	}
	for(i = 0; i < m; i++){
		aux.clear();
		for(j = 0; j < n; j++){
			aux.insert(cadenas[j][i]);
		}
		rta = (rta * aux.size()) % mod;
	}
	cout << rta << "\n";
	return 0;
}

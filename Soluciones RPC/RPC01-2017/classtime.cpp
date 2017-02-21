/************************************************************************
 * Ejercicio:  C Class Time			                         			*
 * Lenguaje: c++                                                    	*
 * Autor: Make Chocoramo Great Again (Melissa Delgado - Gerson Lázaro	*
 * Fecha: 11-02-2017                                            	    *
 ***********************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	map<string, set<string> > orden;
	string nombre, apellido;
	cin >> n;
	while(n-- > 0) {
		cin >> nombre >> apellido;
		orden[apellido].insert(nombre);
	}
	for(map<string, set<string> >::iterator it = orden.begin(); it != orden.end(); ++it) {
		for(set<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			cout << *it2 << " " << it->first << "\n";
		}
	}
	return 0;
}
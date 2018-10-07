/************************************************************************
 * Ejercicio:  D Complexity			                         			*
 * Lenguaje: c++                                                    	*
 * Autor: Make Chocoramo Great Again (Melissa Delgado - Gerson Lázaro	*
 * Fecha: 11-02-2017                                            	    *
 ***********************************************************************/

 #include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin >> s;
	map<char, int> vals;
	for(int i = 0; i < s.size(); i++) {
		vals[s[i]]++;
	}
	if(vals.size() <= 2) cout << "0\n";
	else {
		multiset<int> aux;
		for(map<char, int>::iterator it = vals.begin(); it != vals.end(); ++it) {
			aux.insert(it->second);
		}
		int rta = 0;
		int i = 2;
		for( multiset<int>::iterator it2 = aux.begin(); i < vals.size(); i++, it2++) {
			rta += *it2;
		}
		cout << rta << "\n";
	}
	return 0;
}
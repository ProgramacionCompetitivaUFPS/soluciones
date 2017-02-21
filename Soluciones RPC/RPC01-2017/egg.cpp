/************************************************************************
 * Ejercicio:  F Egg Drop			                         			*
 * Lenguaje: c++                                                    	*
 * Autor: Make Chocoramo Great Again (Melissa Delgado - Gerson Lázaro	*
 * Fecha: 11-02-2017                                            	    *
 ***********************************************************************/

 #include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, k, s, b, a;
	string w;
	
	cin >> n >> k;
	s = 1; b = k;
	
	while( n-- ){
		cin >> a >> w;
		
		if( w == "SAFE" && a > s ) s = a;
		if( w == "BROKEN" && a < b) b = a;
		
	}
	s++;
	b--;
	
	cout << s << " " << b << "\n";
	return 0;
}
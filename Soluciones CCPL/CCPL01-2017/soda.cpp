/********************************************************************
 * Ejercicio: E - Soda Surpler				                        *
 * Lenguaje: c++                                          			*
 * Autor: UFPSTeamLeader (Gerson Lázaro - Melissa Delgado)          *
 * Fecha: 18-02-2017                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int tc, e, f, c, cont;
	
	cin >> tc;
	
	while( tc-- ){
		cin >> e >> f >> c;
		
		e += f;
		
		cont = 0;
		
		while( e >= c ){
			e-=c;
			e++;
			cont++;
		}
		
		cout << cont << "\n";
		
	}
	
	return 0;
}
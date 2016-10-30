/********************************************************************
 * Ejercicio:  B - The Monkey and the Oiled Bamboo                  *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 22-10-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc, n, i, rta, a, s;
	map<int, int> jumps;
	map<int, int>::reverse_iterator it;
	cin >> tc;
	i = 0;
	
	while(i < tc){
		i++;
		cin >> n;
		jumps.clear();
		cin >> a;
		jumps[a]++;
		n--;
		
		while(n > 0){
			cin >> s;
			jumps[s-a]++;
			a = s;
			n--;
		}
		
		it = jumps.rbegin();
		rta = it -> first;
		
		if( jumps[rta] > 1){
			rta++;
		}
		
		cout << "Case " << i << ": " << rta << "\n";
	}
	
	
	return 0;
}
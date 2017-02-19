/********************************************************************
 * Ejercicio: D - The Bus Driver Problem	                        *
 * Lenguaje: c++                                          			*
 * Autor: UFPSTeamLeader (Gerson Lázaro - Melissa Delgado)          *
 * Fecha: 18-02-2017                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d, r, aux;
	long rta;
	vector<int> am, pm;
	cin >> n >> d >> r;

	while(n > 0) {
		am.clear();
		pm.clear();
		rta = 0;
		for(int i = 0; i < n; i++) {
			cin >> aux;
			am.push_back(aux);
		}
		for(int i = 0; i < n; i++) {
			cin >> aux;
			pm.push_back(aux);
		}
		sort(am.begin(), am.end());
		sort(pm.begin(), pm.end());
		for(int i = 0; i < n; i++) {
			if(am[i] + pm[n - i - 1] > d) {
				rta += ((am[i] + pm[n - i - 1] - d) * r);				
			}
		}
		cout << rta << "\n";
		cin >> n >> d >> r;
	}
	
	return 0;
}
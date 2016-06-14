/********************************************************************
 * Ejercicio: E. Squawk Virus	                                    *
 * Url: https://acm.javeriana.edu.co/maratones/2016/06              *
 * Lenguaje: c++	                                                *
 * Autor: Siquelazos (Melissa Delgado - Daniel Vega - Gerson Lázaro *                                                    *
 * Fecha: 11-06-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int> ady [110];
long long squaks [110][10];
int m, n, t;
long long rta;
set<int> state;

void simulate(int tt){
	int a, i;
	set<int>::iterator it;
	it = state.begin();
	set<int> nextTime;
	
	while(it != state.end() ){
		a = *it;
		
		for(i = 0; i < ady[a].size(); i++){
			squaks[ ady[a][i] ][tt] += squaks[ a ][ tt - 1];
			if(tt == t){
				rta += squaks[ a ][ tt - 1];
			}
			nextTime.insert( ady[a][i] );
		}
		it++;
	}
	
	state.swap(nextTime);
	if(tt < t){
		simulate(tt+1);
	}
}

int main() {
	int s, o, d;
	
	cin>>n>>m>>s>>t;
	
	while(m>0){
		cin>>o>>d;
		ady[o].push_back(d);
		ady[d].push_back(o);
		m--;
	}
	
	rta = 0;
	state.insert(s);
	squaks[s][0] = 1;
	simulate(1);
	cout<<rta<<endl;
	
	
}

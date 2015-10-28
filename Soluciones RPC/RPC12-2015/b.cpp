/********************************************************************
 * Ejercicio: Button Bashing	                                    *
 * Url: https://acm.javeriana.edu.co/maratones/2015/12              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 24-10-2015                                                *
 *******************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

/*
	'Cause I'm back
	Yes, I'm back
	Well, I'm back ~( '.' ~)
*/

using namespace std;

int n, t, cb, ttotal;
int buttons[17];
map<int, int> estados;

struct State{
	int tiempo;
	int cont;
};

void bfs(){
	queue<State> q;
	int i, aux, tt, c;
	ttotal=cb=3650;

	for(i=0; i<n; i++){
		aux=buttons[i];
		aux=(aux<0)?0:aux;

		estados[aux]++;
		q.push(State {aux, 1});
	}

	while(!q.empty()){
		tt=q.front().tiempo;
		c=q.front().cont;
		q.pop();

		if(tt==t){
			ttotal=tt;
			cb=c;
			return;
		}

		if(tt>t){
			if(tt<ttotal){
				ttotal=tt;
				cb=c;
			}
		}

		for(i=0; i<n; i++){
			aux=tt+buttons[i];
			aux=(aux>3600?3600:aux);
			aux=(aux<0?0:aux);

			if(estados[aux]==0){
				estados[aux]++;
				q.push(State {aux, c+1});
			}
		}
	}
}

int main(){
	int tc, i;
	cin>>tc;

	while(tc>0){
		cin>>n>>t;
		estados.clear();
		for(i=0; i<n; i++){
			cin>>buttons[i];
		}
		bfs();
		cout<<cb<<" "<<ttotal-t<<"\n";
		tc--;
	}
}
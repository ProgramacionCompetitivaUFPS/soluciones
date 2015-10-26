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
#include <climits>

using namespace std;

int ady[17];
int n, t, tt, cont;

struct State{
	int buttonV;
	int time;
	int bCount;
};

void microWave(){
	queue<State> q;
	int tMayor, bcMayor;
	int i, bv, tm, bc;
	
	tMayor=bcMayor=INT_MAX;
	for(i=0; i<n; i++){
		q.push(State {ady[i], 0, 0});
	}

	while(!q.empty()){
		bv=q.front().buttonV;
		tm=q.front().time;
		bc=q.front().bCount+1;
		q.pop();

		tm+=bv;

		if(tm<0)
			tm=0;
		
		if(tm>3600){
			tm=3600;
			break;
		}

		if(tm>t){
			if(tm<tMayor){
				tt=tMayor=tm;
				cont=bcMayor=bc;
			}
		}
		
		if(tm==t){
			tt=tm;
			cont=bc;
			break;
		}

		for(i=0; i<n; i++){
			q.push(State {ady[i], tm, bc});
		}
	}
}

int main() {
	int tc, i, j, x;
	cin>>tc;
	while(tc>0){
		cin>>n>>t;
		for(i=0; i<n; i++){
			cin>>x;
			ady[i]=x;
		}
		tt=cont=0;
		microWave();
		cout<<cont<<" "<<tt-t<<"\n";
		tc--;
	}
	return 0;
}
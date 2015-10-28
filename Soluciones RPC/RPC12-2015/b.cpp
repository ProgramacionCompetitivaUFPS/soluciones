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
 #include <map>

using namespace std;

int ady[17];
int n, t, tt, cont;
map<int, int> estados;

struct State{
	//int buttonV;
	int time;
	int bCount;
};

void microWave(){
	queue<State> q;
	int tMayor, bcMayor;
	int i, tm, bc, aux, x;
	bool flag=false;
	
	tMayor=bcMayor=INT_MAX;
	for(i=0; i<n; i++){
		x=ady[i]<0?0:ady[i];
		estados[x]++;
		q.push(State { x, 1});
		//q.push(State {ady[i], x, 1});
	}

	while(!q.empty()){
		//bv=q.front().buttonV;
		tm=q.front().time;
		bc=q.front().bCount+1;
		q.pop();

		for(i=0; i<n; i++){
			aux=tm+ady[i];
			
			if(aux==t){
				tt=aux;
				cont=bc;
				flag=true;
				break;
			}

			if(aux<0)
				aux=0;

			if(aux>3600)
				aux=3600;

			if(aux>t){
				if(aux<tMayor){
					tt=tMayor=aux;
					cont=bcMayor=bc;
				}
			}

			if(estados[aux]==0){
				estados[aux]++;
				q.push(State {aux, bc});
				//q.push(State {ady[i], tm, bc});
			}
			
		}

		if(flag){
			break;
		}
	}
}

int main() {
	int tc, i, j, x;
	cin>>tc;
	while(tc>0){
		estados.clear();
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
/********************************************************************
 * Ejercicio: Toby the adventurer                                   *
 * Url: https://acm.javeriana.edu.co/maratones/2015/03_div2         *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 11-04-2015                                                *
 *******************************************************************/

#include <bits/stdc++.h>
#define endl "\n"
#define Node pair<int,int> //destino, peso

using namespace std;

int visitados, n;
long long costo;
vector<Node> ady[10001];
int anterior[10001];
int distancia[10001];

void init(){
	int i;
	visitados=0;
	costo=0;
	for(i=0; i<n; i++){
		ady[i].clear();
		anterior[i]=-1;
		distancia[i]=-1;
	}
}

int validarRuta(int actual, int ruta){
	if(anterior[actual]==ruta){
		return 1;
	}else if(anterior[actual]==-1){
		return -1;
	}

	return validarRuta(anterior[actual], ruta);
}

void buscarRuta(int actual){
	visitados++;
	int i, destino, peso, aux;
	for(i=0; i<ady[actual].size(); i++){
		destino=ady[actual][i].first;
		peso=ady[actual][i].second;
		if(distancia[destino]==-1){
			costo+=peso;
			distancia[destino]=peso;
			anterior[destino]=actual;
			buscarRuta(destino);
		}else if(distancia[destino]>peso){
			aux=validarRuta(actual, destino);
			if(aux==-1){
				costo-=(distancia[destino]-peso);
				distancia[destino]=peso;
				anterior[destino]=actual;
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    int tc, m, origen, i, src, dest, peso;
    cin>>tc;
    while(tc>0){
    	cin>>n>>m>>origen;
    	init();
    	for(i=0; i<m; i++){
    		cin>>src>>dest>>peso;
    		ady[src].push_back(Node(dest, peso));
    	}
    	buscarRuta(origen);

    	if(visitados==n){
    		cout<<costo<<endl;
    		for(i=0; i<n; i++){
    			if(i!=origen){
    				cout<<anterior[i]<<" "<<i<<" "<<distancia[i]<<endl;
    			}
    		}

    	}else{
    		cout<<"impossible"<<endl;
    	}
		tc--;
    }
}
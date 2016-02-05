/********************************************************************
 * Ejercicio: Level order tree traversal                            *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1466
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<int, int> adyIzq;
map<int, int> adyDer;
int root;

void crearArbol(int r){
	adyIzq.clear();
	adyDer.clear();
	adyIzq[r] = -1;
	adyDer[r] = -1;
	root = r;
}

void insertar(int valor, int padre){
	if(valor < padre){
		if(adyIzq[padre] != -1){
			insertar(valor, adyIzq[padre]);
		}else{
			adyIzq[padre] = valor;
			adyIzq[valor] = -1;
			adyDer[valor] = -1;
		}
	}else{
		if(adyDer[padre] != -1){
			insertar(valor, adyDer[padre]);
		}else{
			adyDer[padre] = valor;
			adyIzq[valor] = -1;
			adyDer[valor] = -1;
		}
	}
}

void imprimir(){
	queue<int> cola;
	vector<int> lista;
	cola.push(root);
	int aux;
	while(!cola.empty()){
		aux = cola.front();
		cola.pop();
		lista.push_back(aux);
		if(adyIzq[aux] != -1){
			cola.push(adyIzq[aux]);
		}
		if(adyDer[aux] != -1){
			cola.push(adyDer[aux]);
		}
	}
	for(aux = 0; aux < lista.size(); aux++){
		printf("%d", lista[aux]);
		if(aux + 1 < lista.size()){
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	int c, n, a;
	scanf("%d", &c);
	for(int gf = 1; gf <= c; gf++){
		printf("Case %d:\n", gf);
		scanf("%d", &n);
		n--;
		scanf("%d", &a);
		crearArbol(a);
		while(n > 0){
			scanf("%d", &a);
			insertar(a, root);
			n--;
		}
		imprimir();
		printf("\n");
	}
	return 0;
}

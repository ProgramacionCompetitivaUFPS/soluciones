#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#define Point pair<int,int>

/*
 * @author Bashkara's Formulae (team Candelaria):
 *      Gerson Lázaro - Melissa Delgado - Cristhian León
 *      UFPS
*/

using namespace std;

pair<int, int> init=make_pair(0,0);
map<Point, int> puntos;
vector<pair<int, int>> complex(1000, init); //first: personas   second:cantidad
int dx[6] = {0,0,1,-1,-1,1};
int dy[6] = {1,-1,0,0,1,-1};
int cantP, cantC, p, t;

void arregloOptimo(){
	int i,j,k;
	i=t-1;
	for(i; (i>=0 && cantP<p); i--){
		j=complex[i].second;
		k=0;
		while(k<j && cantP<p){
			cantP+=complex[i].first;
			cantC++;
			if(cantC>1)	cantP-=2;
			k++;
		}
	}
}

int main(){

	int tc, i, c, s, aux, x, y;
	Point w;

	scanf("%i", &tc);

	while(tc>0){
		scanf("%i %i", &p, &t);
		i=0;
		for(; i<t; i++){
			scanf("%i %i", &c, &s);
			puntos.clear();
			aux=0;
			while(s>0){
				scanf("%i %i", &x, &y);
				puntos[Point(x, y)]=1;
				aux+=6;
				for(int a=0;a<6;a++){
					w=Point(x+dx[a], y+dy[a]);
					if(puntos[w]==1)  aux-=2;
				}
				s--;
			}
			complex[i]=make_pair(aux,c);
		}

		sort(complex.begin(), complex.begin()+t);
		cantP=cantC=0;
		arregloOptimo();

		if(cantP>=p){
			printf("Je treba %i celku.\n", cantC);
		}else{
			printf("Kapacita zakladny je pouze %i lidi.\n", cantP);
		}

		tc--;
	}
	return 0;
}
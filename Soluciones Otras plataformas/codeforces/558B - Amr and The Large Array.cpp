/********************************************************************
 * Ejercicio: Amr and The Large Array                               *
 * Url: http://codeforces.com/problemset/problem/558/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/

#include <cstdio>
#include <map>
using namespace std;

int main() {
	int n,aux,i;
	scanf("%i",&n);
	map<int, int> numero, inicio, fin;
	for(i=1;i<=n;i++){
		scanf("%i", &aux);
		if(numero[aux]==0){
			inicio[aux]=i;
			fin[aux]=i;
		}else{
			fin[aux]=i;
		}
		numero[aux]++;
	}
	int mayor=-1, cantMayor=-1, dist=0,x,y;
	for(map<int, int>::iterator itNum=numero.begin(), itIn=inicio.begin(), itFin=fin.begin();itNum!=numero.end();++itNum, ++itIn, ++itFin){
		if(itNum->second > cantMayor){
			mayor= itNum->first;
			cantMayor = itNum->second;
			dist = itFin->second - itIn->second;
			x=itIn->second; y=itFin->second;
		}else if(itNum->second == cantMayor){
			if(itFin->second - itIn->second < dist){
				mayor= itNum->first;
				cantMayor = itNum->second;
				dist = itFin->second - itIn->second;
				x=itIn->second; y=itFin->second;
			}
		}
	}
	printf("%i %i\n",x,y);
	return 0;
}
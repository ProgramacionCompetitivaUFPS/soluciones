/********************************************************************
 * Ejercicio: Boomerang Constellations                              *
 * Url: https://www.facebook.com/hackercup/problem/910374079035613/ *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 * Comentarios: A diferencia de ICPC, en Facebook Hackercup es      *
 *     posible leer y escribir entradas directamente en archivos de *
 *     texto. Por comodidad, se leen las entradas desde input.txt y *
 *     se escriben los resultados en output.txt                     *
 *******************************************************************/


#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <utility>

using namespace std;



int main(){
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int i, j, t, n, a, b;
	long long rta;
	map<double, int> mapa;
	scanf("%d",&t);
	for(i = 0; i < t; i++){
		set<pair<int, int> > _set;
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%d %d", &a, &b);
			_set.insert(make_pair(a,b));
		}
		rta = 0;
		for(set<pair<int, int> >::iterator ita= _set.begin(); ita != _set.end(); ++ita){
			mapa.clear();
			for(set<pair<int, int> >::iterator itb = _set.begin(); itb != _set.end(); ++itb){
				mapa[hypot(ita->first - itb->first, ita->second - itb->second)]++;
			}
			for(map<double, int>::iterator itc = mapa.begin(); itc != mapa.end(); ++itc){
				if(itc->first != 0){
					rta += ((long long)itc->second * (long long)(itc->second - 1) / 2);
				}			
			}
		}
		printf("Case #%d: %lld\n", i + 1, rta);
	}
  	return 0;
}

/********************************************************************
 * Ejercicio: Laundro, Matt                                         *
 * Url: https://www.facebook.com/hackercup/problem/1611251319125133/*
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
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;



int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i, j, t, l, n, cant;
	long long m, d, aux;
	pair<long long, long long> temp;
	scanf("%d", &t);
	for(i = 1; i <= t; i++){
		scanf("%d %d %lld %lld", &l, &n, &m, &d);
		priority_queue<pair<long long, long long>, vector<pair<long long int,long long int> >, greater<pair<long long int,long long int> > > lavadoras;
		queue<long long> secadoras;
		for(j = 0; j < n; j++){
			scanf("%lld", &aux);
			lavadoras.push(make_pair(aux, aux));
		}
		cant = 0;
		while(cant < l){
			temp = lavadoras.top();
			lavadoras.pop();
			lavadoras.push(make_pair(temp.first + temp.second, temp.second));
			if(secadoras.size() == m){
				aux = secadoras.front();
				secadoras.pop();
				secadoras.push(max(temp.first, aux) + d);
			}else{
				secadoras.push(temp.first + d);
			}
			cant++;
		}
		printf("Case #%d: %lld\n", i, secadoras.back());
	}
  	return 0;
}

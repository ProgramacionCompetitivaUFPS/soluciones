/********************************************************************
 * Ejercicio: The Price is Correct                                  *
 * Url: https://www.facebook.com/hackercup/problem/512731402225321/ *
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
#include <algorithm>

using namespace std;

long long pasos[100005];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i, j, t, n, ind;
	long long a, b, sum, sumAnt, precioYate, aux, inicio;
	long double rta;
	bool flag;
	scanf("%d", &t);
	for(i = 1; i <= t; i++){
		precioYate = 0;
		scanf("%d %lld %lld", &n, &a, &b);
		for(j = 0; j < n; j++){
			scanf("%lld", &pasos[j]);
			precioYate += pasos[j];
		}
		aux = a / precioYate;
		sum = precioYate * aux;
		ind = 0;
		while(sum <= a){
			sum += pasos[ind];
			ind = (ind + 1) % n;
		}
		ind--;
		if(ind == -1){
			ind = n - 1;
		}
		sum -= pasos[ind];
		inicio = a - sum;
		sumAnt = sum;
		rta = 0;
		flag = false;
		while(sum < b){
			sum += pasos[ind];
			if(!flag && sum <= b){
				rta += ((long double)((long double)(sum - sumAnt) + (long double)(inicio)) / 2) * (long double)(sum - a);
				flag = true;
			}else if(sum <=b){
				rta += (long double)((long double)(sum - sumAnt) / 2) * (long double)(sum - sumAnt); 
			}else if(!flag){
				rta += (long double)((long double)((long double)(b - sumAnt) + (long double)(inicio)) / 2) * (long double)(b - a);
			}else{
				rta += (long double)((long double)(b - sumAnt) / 2) * (long double)(b - sumAnt);
			}
			ind = (ind + 1) % n;
			sumAnt = sum;
		}
		rta /= (long double)(b - a);
		printf("Case #%d: %.9Lf\n", i, rta);
	}
  	return 0;
}

/********************************************************************
 * Ejercicio:  B - Baking Cakes with Grandma                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 27-02-2016                                                *
 *******************************************************************/

#include <iostream>
#include <set>
using namespace std;

set<int> div;

void calcularDivisores(int total){
	div.clear();
	div.insert(1);
	div.insert(total);
	for(int i = 2; i * i <= total; i++) {
		if(total % i == 0) {
			div.insert(i);
			div.insert(total / i);
		}	
	}
}


int main() {
	int n, i, j, partes,p, sum, ult, aux, cant, ini;
	while(cin >> n) {
		int value[2 * n], mayor = 0, total = 0;
		for(i = 0; i < n; i++) {
			cin >> value[i];
			total += value[i];
			if(value[i] > mayor){
				mayor = value[i];
			}
		}
		for(j = 0; i < 2 * n; i++, j++){
			value[i] = value[j];
		}
		calcularDivisores(total);
		for(set<int>::iterator it = div.begin(); it != div.end(); ++it){
			if(*it >= mayor && total / *it >= 3) {
				aux=0;
				cant=0;
				ini=0;
				for(i=0; i<2*n; i++){
					aux+=value[i];
					if(aux==*it){
						aux=0;
						cant++;
						ini=i+1;
						if(cant==total/(*it)){
							cout<<cant;
							goto final;
						}
					}if(aux>*it){
						aux=0;
						cant=0;
						i=ini;
						ini=i+1;
					}
				}
			} 
		}
		
		cout<<"-1";
		final:
		cout<<"\n";
		
	}
	return 0;
}
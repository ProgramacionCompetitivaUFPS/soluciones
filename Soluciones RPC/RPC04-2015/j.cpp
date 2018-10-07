/********************************************************************
 * Ejercicio: Jacksonville Police Departament                       *
 * Url: https://acm.javeriana.edu.co/maratones/2015/04              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 09-05-2015                                                *
 *******************************************************************/

#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int numap, fav, i, aux, j;
	cin>>numap>>fav;
	set<int> ap;
	while(numap!=0 && fav!=0){
		ap.clear();
		for(i=0; i<fav; i++){
			cin>>aux;
			j=aux;
			while(j<=numap){
				ap.insert(j);
				j+=aux;
			}
		}
		cout<<ap.size()<<"\n";
		cin>>numap>>fav;
	}
	return 0;
}
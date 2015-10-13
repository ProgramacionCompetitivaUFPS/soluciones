/********************************************************************
 * Ejercicio: Pizza voting 			                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/01              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2015                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
	int caloria;
	string pizza;
	int casos, fav;
	cin >> casos >> fav;
	if(casos%3==1){
		if((fav>casos/3 && fav<=(casos*2/3)+1)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}else{
		if((fav>casos/3 && fav<=casos*2/3)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
	
	while(casos>0){
		cin >> caloria;
		cin >> pizza;
		casos--;
	}
	return 0;
}
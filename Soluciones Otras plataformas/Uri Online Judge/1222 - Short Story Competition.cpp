/********************************************************************
 * Ejercicio: Short Story Competition                               *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1222
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
 #include <iostream>
using namespace std;

int main() {
	int a, b, c, car, lin, pags;
	string aux;
	while(cin >> a >> b >> c){
		car = 0;
		lin = 0;
		pags = 0;
		while(a > 0){
			cin >> aux;
			if(car + aux.size() <= c){
				car += aux.size() + 1;
			}else{
				car = aux.size() + 1;
				lin++;
				if(lin == b){
					pags++;
					lin = 0;
				}
			}
			a--;
		}
		pags++;
		cout << pags << "\n";
	}
	return 0;
}

/********************************************************************
 * Ejercicio: Diamonds and sand                                     *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1069
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, i, num1, rta;
	string k;
	cin >> n;
	while(n > 0){
		cin >> k;
		num1 = 0;
		rta = 0;
		for(i = 0; i < k.size(); i++){
			if(k[i] == '<'){
				num1++;
			}else if(k[i] == '>'){
				if(num1 > 0){
					num1--;
					rta++;
				}
			}
		}
		cout << rta << endl;
		n--;
	}
	return 0;
}

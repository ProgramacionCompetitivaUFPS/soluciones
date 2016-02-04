/********************************************************************
 * Ejercicio: Grandfather Dovlet’s calculator                       *
 * Url: http://codeforces.com/problemset/problem/620/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/

#include <iostream>
using namespace std;

long long val[1000007];
long long rta[10];

void calcular(){
	rta[0] = 6;
	rta[1] = 2;
	rta[2] = 5;
	rta[3] = 5;
	rta[4] = 4;
	rta[5] = 5;
	rta[6] = 6;
	rta[7] = 3;
	rta[8] = 7;
	rta[9] = 6;
	val[0] = 6;
	int aux;
	for(int i = 1; i < 1000007; i++){
		aux = i;
		val[i] = val[i - 1];
		while(aux > 0){
			val[i] += rta[aux % 10];
			aux /= 10;
		}
	}
}

int main() {
	calcular();
	int a,b;
	cin >> a >> b;
	if(a == 0){
		cout << val[a] << endl;
	}else{
		cout << val[b] - val[a - 1] << endl;
	}
	
	return 0;
}

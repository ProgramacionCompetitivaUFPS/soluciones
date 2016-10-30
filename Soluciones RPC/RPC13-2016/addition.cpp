/********************************************************************
 * Ejercicio:  A. ASCII Addition                                    *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 08-10-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;

map<string, int> num;
map<int, string> rev;

int calcDigitos(long long n){
	int d = 0;
	while(n > 0) {
		d++;
		n /= 10;
	}
	return d;
}

long long obtDivisor(int d, int c) {
	return pow(10, (c - d - 1));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	num["xxxxxx...xx...xx...xx...xx...xxxxxx"] = 0;
	num["....x....x....x....x....x....x....x"] = 1;
	num["xxxxx....x....xxxxxxx....x....xxxxx"] = 2;
	num["xxxxx....x....xxxxxx....x....xxxxxx"] = 3;
	num["x...xx...xx...xxxxxx....x....x....x"] = 4;
	num["xxxxxx....x....xxxxx....x....xxxxxx"] = 5;
	num["xxxxxx....x....xxxxxx...xx...xxxxxx"] = 6;
	num["xxxxx....x....x....x....x....x....x"] = 7;
	num["xxxxxx...xx...xxxxxxx...xx...xxxxxx"] = 8;
	num["xxxxxx...xx...xxxxxx....x....xxxxxx"] = 9;
	num[".......x....x..xxxxx..x....x......."] = 10;
	rev[0] = "xxxxxx...xx...xx...xx...xx...xxxxxx";
	rev[1] = "....x....x....x....x....x....x....x";
	rev[2] = "xxxxx....x....xxxxxxx....x....xxxxx";
	rev[3] = "xxxxx....x....xxxxxx....x....xxxxxx";
	rev[4] = "x...xx...xx...xxxxxx....x....x....x";
	rev[5] = "xxxxxx....x....xxxxx....x....xxxxxx";
	rev[6] = "xxxxxx....x....xxxxxx...xx...xxxxxx";
	rev[7] = "xxxxx....x....x....x....x....x....x";
	rev[8] = "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
	rev[9] = "xxxxxx...xx...xxxxxx....x....xxxxxx";
	rev[10] = ".......x....x..xxxxx..x....x.......";
	
	string str;
	
	while(cin >> str) {
		long long vals[3], divisor, aux;
		int ind, cant;
		string rta;
		string cad[7];
		rta = "";
		vals[0] = vals[1] = ind = 0;
		cad[0] = str;
		for(int i = 1; i < 7; i++) {
			cin >> cad[i];
		}
		
		for(int i = 0; i + 4 < cad[0].size(); i += 6) {
			str = "";
			for(int j = 0; j < 7; j++) {
				str += cad[j].substr(i, 5);
			}
			if(num[str] == 10) {
				ind++;
			} else {
				vals[ind] *= 10;
				vals[ind] += num[str];
			}
		}
		vals[2] = vals[1] + vals[0];
		for(int i = 0; i < 7; i++) {
			cant = calcDigitos(vals[2]);
			aux = vals[2];
			for(int j = 0, k = 0; cant > 0; k++) {
				divisor = obtDivisor(j, cant);
				rta += rev[aux / divisor].substr(i * 5, 5);
				if(cant != 1) {
					rta += ".";
				}
				aux %= divisor;
				cant--;
			}
			rta += "\n";
		}
		cout << rta;
	}
	return 0;
}
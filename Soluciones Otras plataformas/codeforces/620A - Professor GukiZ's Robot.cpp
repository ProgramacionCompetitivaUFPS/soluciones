/********************************************************************
 * Ejercicio: Professor GukiZ's Robot                               *
 * Url: http://codeforces.com/problemset/problem/620/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	long long x1, y1, x2, y2,men;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2 && y1 == y2){
		cout << "0\n";
	}else if(x1 == x2){
		cout << abs(y2 - y1) << "\n";
	}else if(y1 == y2){
		cout << abs(x2 - x1) << "\n";
	}else{
		if(x1 < x2 && y1 < y2){
			men = min(x2 - x1, y2 - y1);
			x2 -= men;
			y2 -= men;
		}else if(x1 < x2 && y1 > y2){
			men = min(x2 - x1, y1 - y2);
			x2 -= men;
			y2 += men;
		}else if(x1 > x2 && y1 > y2){
			men = min(x1 - x2, y1 - y2);
			x2 += men;
			y2 += men;
		}else if(x1 > x2 && y1 < y2){
			men = min(x1 - x2, y2 - y1);
			x2 += men;
			y2 -= men;
		}
		
		
		if(x1 == x2 && y1 == y2){
			cout << men << "\n";
		}else if(x1 == x2){
			cout << abs(y2 - y1) + men << "\n";
		}else if(y1 == y2){
			cout << abs(x2 - x1) + men << "\n";
		}
		
	}
	
	return 0;
}

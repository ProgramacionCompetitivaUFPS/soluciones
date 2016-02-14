/********************************************************************
 * Ejercicio:  C Colbys Costly Collectibles                         *
 * Url: https://acm.javeriana.edu.co/maratones/2016/01/             *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2016                                                *
 *******************************************************************/

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


struct point { 
	double x, y;
  	point() { 
  		x = y = 0.0; 
  	}
  	point(double _x, double _y) : x(_x), y(_y) {}        
  	bool operator == (point other) const {
   		return (fabs(x - other.x) < 1e-9 && (fabs(y - other.y) < 1e-9)); 
   	}
};

double area(vector<point> P) {
	double result = 0.0, x1, y1, x2, y2;
  	for (int i = 0; i < P.size()-1; i++) {
    	x1 = P[i].x; 
    	x2 = P[i+1].x;
    	y1 = P[i].y; 
    	y2 = P[i+1].y;
    	result += ((x1 * y2) - (x2 * y1));
  	}
  	return fabs(result) / 2.0; 
}

int main() {
	int t, i, n, num;
	double x, y;
	char caracter;
	cin >> t;
	while(t){
		cin >> n;
		vector<point> figura;
		x = y = 0;
		figura.push_back(point(x,y));
		for(i = 0; i < n; i++){
			cin >> caracter >> num;
			if(caracter == 'x'){
				x += num;
				
			}else if(caracter == 'y'){
				y += num;
				x += (double)num / 2;
			}else if(caracter == 'z'){
				y += num;
				x -= (double)num / 2;
			}
			figura.push_back(point(x, y));
		}
		cout << (int)(area(figura) * 2) << "\n";
		t--;
	}
	return 0;
}
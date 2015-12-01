/********************************************************************
 * Ejercicio: Ilya and Diplomas                                     *
 * Url: http://codeforces.com/problemset/problem/557/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/


#include <iostream>
using namespace std;

int main() {
	long long n, min1,min2,min3,max1,max2,max3,rta1, rta2, rta3,rta;
	cin >> n >> min1 >> max1 >> min2 >> max2 >> min3 >> max3; 
	rta=min1+min2+min3;
	rta1=min1;
	rta2=min2;
	rta3=min3;
	if(rta<n){
		if(n-rta>max1-min1){
			rta1=max1;
			rta=max1+min2+min3;
			if(n-rta>max2-min2){
				rta2=max2;
				rta=max1+max2+min3;
				if(n-rta>max3-min3){
					rta3=max3;
				}else{
					rta3=n-rta+min3;
				}
			}else{
				rta2= n-rta+min2;
			}
		}else{
			rta1 = n-rta+min1;
		}
	}
	cout << rta1 << " " << rta2 << " " << rta3 << "\n";
	return 0;
}
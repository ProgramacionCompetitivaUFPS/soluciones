/********************************************************************
 * Ejercicio: Computenis recargado                                  *
 * Url: https://acm.javeriana.edu.co/maratones/2015/10              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 26-09-2015                                                *
 *******************************************************************/
#include <iostream>
using namespace std;

int main() {
	int a,b,c,d;
	int pa=0, pb=0;
	int ga=0, gb=0;
	string m;
	cin >> a >> b >> c >> d >> m;
	for(int i=0; i < a; i++){
		if(m[i] == 'A'){
			pa++;
		}else{
			pb++;
		}
		if(pa >= c && pa-pb >= d){
			pa = 0;
			pb = 0;
			ga++;
		}else if(pb >= c && pb-pa >= d){
			pa = 0;
			pb = 0;
			gb++;
		}
	}
	cout << ga << " " << gb << "\n";
	return 0;
}

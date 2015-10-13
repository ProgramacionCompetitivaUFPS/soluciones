/********************************************************************
 * Ejercicio: Numeric Center                                        *
 * Url: https://acm.javeriana.edu.co/maratones/2015/03_div2         *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 11-04-2015                                                *
 *******************************************************************/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	vector<unsigned long long> limites;
	limites.push_back(8);
	limites.push_back(49);
	limites.push_back(288);
	limites.push_back(1681);
	limites.push_back(9800);
	limites.push_back(57121);
	limites.push_back(332928);
	long long caso,i,rta;
	double factor = 5.828427125;
	unsigned long long aux=275807,aux2;
	unsigned long long referencia = pow(10,14);
	int ni = 6;
	for(;aux<=referencia;){
		aux2=aux;
		aux = (unsigned long long)((aux*factor));
		limites.push_back(limites[ni]+aux);
		ni++;
		factor = (long double)aux/aux2;
	}
	cin >> caso;
	while(caso!=0){
		i=0;
		rta=0;
		while(true){
			if(caso>=limites[i]){
				rta++;	
			}else{
				break;
			}
			i++;
		}
		cout << rta << "\n";
		cin >> caso;
	}
	return 0;
}
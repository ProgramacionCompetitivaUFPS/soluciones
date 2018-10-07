/********************************************************************
 * Ejercicio: H -  Through the Desert    	                        *
 * Lenguaje: c++                                          			*
 * Autor: UFPSTeamLeader (Gerson Lázaro - Melissa Delgado)          *
 * Fecha: 18-02-2017                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int km, t, leaks, leakTime, fuelTime;
	double tasa, aux, rta;
	string event, s;
	
	leakTime = fuelTime = 0;
	leaks = 0;
	rta = aux = 0.0;
	
	while( cin >> km ){
		cin >> event;
		
		if( event == "Fuel"){
			cin >> s >> t;
			if( t == 0 )	break;
			
			rta += ( km - fuelTime ) * tasa;
			
			tasa = (double)t/100.0;
			fuelTime = km;
		}else if( event == "Leak"){
			if( leaks > 0 ){
				rta += ( km - leakTime ) * leaks;
			}
			leaks++;
			leakTime = km;
		}else if( event == "Gas"){
			cin >> s;
			rta += ( km - fuelTime ) * tasa;
			rta += ( km - leakTime ) * leaks;
			
			aux = max(rta, aux);
			
			rta = 0.0;
			leakTime = km;
			fuelTime = km;
		}else if( event == "Mechanic"){
			rta += ( km - leakTime ) * leaks;
			leakTime = 0;
			leaks = 0;
		}else{
			rta += ( km - fuelTime ) * tasa;
			rta += ( km - leakTime ) * leaks;
			rta = max(rta, aux);
			
			printf("%.3f\n", rta);
			rta = 0.0;
			aux = 0.0;
			km = 0;
			leaks = 0;
			leakTime = fuelTime = 0;
		}
	}
	
	

	
	return 0;
}
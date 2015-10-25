/********************************************************************
 * Ejercicio: Growling Gears	                                    *
 * Url: https://acm.javeriana.edu.co/maratones/2015/12              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 24-10-2015                                                *
 *******************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int casos, n, a, b, c, i, iMayor;
	long long t, tMayor;
	cin>>casos;
	while(casos>0){
		cin>>n;
		tMayor=0;
		iMayor=0;
		for(i=1; i<=n; i++){
			cin>>a>>b>>c;
			a*=-1;
			t=c-(pow(b,2)/(4*a));
			if(t>tMayor){
				tMayor=t;
				iMayor=i;
			}
		}
		cout<<iMayor<<"\n";
		casos--;
	}
	return 0;
}
/********************************************************************
 * Ejercicio: Vowel Count		                                    *
 * Url: https://acm.javeriana.edu.co/maratones/2015/12              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 24-10-2015                                                *
 *******************************************************************/

#include <iostream>

using namespace std;

int main() {
	int casos, i;
	string cad;
	int v, l;
	cin>>casos;
	while(casos>0){
		cin>>cad;
		v=l=0;
		for(i=0; i<cad.size(); i++){
			if(cad[i]=='a' || cad[i]=='e' || cad[i]=='i'|| cad[i]=='o'|| cad[i]=='u'){
				v++;
			}else{
				l++;
			}
		}
		cout<<cad<<"\n";
		if(v>l){
			cout<<1<<"\n";
		}else{
			cout<<0<<"\n";
		}
		casos--;
	}
	return 0;
}
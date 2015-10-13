/********************************************************************
 * Ejercicio: My brother’s diary 	                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/01              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2015                                                *
 *******************************************************************/

#include <iostream>
#include <map>
using namespace std;
int main() {
	int casos,i, mayor, dist;
	char letraMayor;
	bool bandera;
	string frase;
	cin >> casos;
	getline(cin, frase);
	while(casos>0){
		map<char, int> mapa;
		getline(cin,frase);
		for(i=0;i<frase.length();i++){
			if(frase.at(i)!=' '){
				mapa[frase.at(i)]++;
			}
		}
		mayor = 0;
		bandera = false;
		for(map<char,int>::iterator it = mapa.begin();it!=mapa.end();it++){
			if(it->second>mayor){
				mayor = it->second;
				letraMayor = it->first;
				bandera = false;
			}else if(it->second==mayor){
				bandera = true;
			}
		}
		if(bandera){
			cout << "NOT POSSIBLE\n";
		}else{
			dist = (26+((int)letraMayor-(int)'E')) % 26; 
			cout << dist << " ";
			for(i=0;i<frase.length();i++){
				if(frase.at(i)!=' '){
					if((int)frase.at(i)-dist < 65){
						cout << (char)(26+frase.at(i)-dist);
					}else{
						cout <<(char)(frase.at(i)-dist);
					}
				}else{
					cout << " ";
				}
			}
			cout << "\n";
		}
		casos--;
	}
	return 0;
}
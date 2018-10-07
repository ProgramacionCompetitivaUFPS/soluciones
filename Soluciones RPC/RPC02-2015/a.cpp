/********************************************************************
 * Ejercicio: Eight Queens 			                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/02              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-03-2015                                                *
 *******************************************************************/

#include <iostream>
#define endl "\n"
using namespace std;

int main() {
	bool flag=true;int cont=0;
	int horizontal[8];
	int vertical[8];
	int diagPrinc[15];
	int diagSec[15];
	int i,j; 
	for(i=0; i<8; i++){
		horizontal[i]=0;
		vertical[i]=0;
		diagPrinc[i]=0;
		diagSec[i]=0;
	}
	
	for(i=8; i<15; i++){
		diagPrinc[i]=0;
		diagSec[i]=0;
	}
	string x;
	for(i=0; i<8; i++){
		cin>>x;
		if(flag){
			for(j=0;  j<8;j++){
				if(flag){
					if(x.at(j)=='*'){
						cont++;
						if(horizontal[i]==1 || vertical[j]==1 || diagPrinc[j-i+7]==1 || diagSec[i+j]==1){
							flag=false;
						}else{
							horizontal[i]=1;
							vertical[j]=1;
							diagPrinc[j-i+7]=1;
							diagSec[i+j]=1;
						}
					}
				}
			}
		}
	}

	if(cont==8 && flag){
		cout<<"valid"<<endl;
	}else{
		cout<<"invalid"<<endl;
	}
	
	return 0;
}
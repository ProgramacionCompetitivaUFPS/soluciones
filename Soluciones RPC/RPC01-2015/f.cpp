/********************************************************************
 * Ejercicio: Gold Rush				                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/01              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-02-2015                                                *
 *******************************************************************/

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <climits>
#include <vector>
#include <math.h>
#define endl "\n"


using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main() {
	long long x;
	long long potencias[63];
	potencias[0]=1;
	potencias[1]=2;
	for(int i=2; i<63; i++){
		potencias[i]=pow(2, i);
	}
	
	int casos, n, cont;
	long long a,b, menor;
	
	
	cin>>casos;
	
	while(casos>0){
		cin>>n>>a>>b;
		if(a<b){
			menor=a;
		}else{
			menor=b;
		}
		cont=0;
		for(int i=n; i>=0; i--){
			if(potencias[i]==menor){
				break;
			}else if(potencias[i]<menor){
				if(menor%potencias[i]==0){
					break;
				}
			}
			cont++;
		}
		cout<<cont<<endl;
		casos--;
	}
	
	return 0;
}
/********************************************************************
 * Ejercicio: The book thief                                        *
 * Url: https://acm.javeriana.edu.co/maratones/2015/03_div2         *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 11-04-2015                                                *
 *******************************************************************/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    long long sumPaginas, triangularS, n;
	long long triangulares[15000];
	
    for(n=1; n<15000; n++){
    	triangulares[n]=(n*(n+1))/2;
    }
    
    cin>>sumPaginas;
    while(sumPaginas!=0){
    	n=floor((-1+sqrt(1+(8*sumPaginas)))/2);
    	triangularS=triangulares[n];
    	while(triangularS<=sumPaginas){
    		n++;
    		triangularS=triangulares[n];
    	}
    	
    	cout<<triangularS-sumPaginas<<" "<<n<<endl;
    	cin>>sumPaginas;
    }
}
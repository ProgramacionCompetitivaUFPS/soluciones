/********************************************************************
 * Ejercicio: Toby and the strange function                         *
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
    unsigned long long t,n, r;
    string x;
    cin>>t;
    while(t>0){
    	cin>>n>>x;
    	r=n%x.length();
    	cout<<x.substr((x.length()-r), r)<<x.substr(0, x.length()-r)<<endl;
    	
    	t--;
    }
}
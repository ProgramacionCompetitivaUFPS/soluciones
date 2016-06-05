/********************************************************************
 * Ejercicio:  J- Jumbled Communication		                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 04-06-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	map<int, int> temp;
	int i, n, t, j;
	
	i = 0;
	while(temp.size()<256){
		j = i<<1;
		if(j>255){
			j -= 256;
		}
		t = i ^ ( j );
		if( t >= 0 && t < 256){
			temp[t] = i;
		}
		i++;
	}
	
	while(cin>>n){
		while(n>0){
			cin>>i;
			cout<<temp[i];
			n--;
			if(n>0){
				cout<<" ";
			}
		}
		cout<<"\n";
	}

	return 0;
}
/********************************************************************
 * Ejercicio:  H - huaauhahhuahau                                   *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 10-09-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int i, j;
	string s;
	bool flag;
	
	while( cin >> s ){
		flag = true;
		i = 0;
		j = s.size()-1;
		
		while( i < j && s[i] != 'a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
			i++;
		}
		
		while( j >= i  && s[j] != 'a' && s[j]!='e' && s[j]!='i' && s[j]!='o' && s[j]!='u'){
			j--;
		}
		
		while(i <= j){
			// cout<<i<<" "<<j<<endl;
			if(s[i] != s[j]){
				flag = false;
				break;
			}
			i++;
			j--;
			
			while( i <= j && s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
				i++;
			}
			
			while( j >= i  && s[j] != 'a' && s[j]!='e' && s[j]!='i' && s[j]!='o' && s[j]!='u'){
				j--;
			}
		}
		
		if(flag){
			cout<<"S\n";
		}else{
			cout<<"N\n";
		}
	}
	return 0;
}
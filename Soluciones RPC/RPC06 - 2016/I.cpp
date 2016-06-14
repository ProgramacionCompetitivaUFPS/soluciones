/********************************************************************
 * Ejercicio: I. What’s on the Grille?                              *
 * Url: https://acm.javeriana.edu.co/maratones/2016/06              *
 * Lenguaje: c++	                                                *
 * Autor: Siquelazos (Melissa Delgado - Daniel Vega - Gerson Lázaro *                                                    *
 * Fecha: 11-06-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
 
using namespace std;

bool myfunction ( const pair<int, int>& i, const pair<int, int>& j ) {
    if( i.first > j.first ) return false;
    if( j.first > i.first ) return true;
    return j.second > i.second;
}

int main() {
	int n, i, j, k, iPalabra;
	string s, rta;
	cin>>n;
	char sms[n][n];
	bool flag = true;
	vector< pair<int,int> > uno;
	vector< pair<int,int> > dos;
	vector< pair<int,int> > tres;
	vector< pair<int,int> > cuatro;
 
	memset(sms, 'X', sizeof(sms[0][0])*n*n );
	
	for(i=0; i<n; i++){
		cin>>s;
		for(j=0; j<n; j++){
			if(s[j] == '.'){
				uno.push_back(make_pair(i, j));
				dos.push_back(make_pair(j, n-1-i));
				tres.push_back(make_pair(n-1-i, n-1-j));
				cuatro.push_back(make_pair(n-1-j, i));
			}
		}
	}
	
	sort(dos.begin(), dos.end(), myfunction);
	sort(tres.begin(), tres.end(), myfunction);
	sort(cuatro.begin(), cuatro.end(), myfunction);
	
	cin>>s;
	
	iPalabra = 0;
	
	for(k=0; k<uno.size(); k++){
		i = uno[k].first;
		j = uno[k].second;
		
		// cout<<i<<" "<<j<<endl;
		if(sms[i][j] != 'X'){
			flag = false;
			break;
		}
		sms[i][j] = s[iPalabra];
		iPalabra++;
	}
	
	// cout<<"unoo "<<flag<<endl;
	
	if(flag){
		for(k=0; k<dos.size(); k++){
			i = dos[k].first;
			j = dos[k].second;
			
			// cout<<i<<" "<<j<<endl;	
			if(sms[i][j] != 'X'){
				flag = false;
				break;
			}
			
			sms[i][j] = s[iPalabra];
			iPalabra++;
		}	
	}
	
	// cout<<"dos "<<flag<<endl;
	
	if(flag){
		for(k=0; k<tres.size(); k++){
			i = tres[k].first;
			j = tres[k].second;
			
			// cout<<i<<" "<<j<<endl;
			if(sms[i][j] != 'X'){
				flag = false;
				break;
			}
			
			sms[i][j] = s[iPalabra];
			iPalabra++;
		}	
	}
	
	// cout<<"tres "<<flag<<endl;
	
	if(flag){
		for(k=0; k<cuatro.size(); k++){
			i = cuatro[k].first;
			j = cuatro[k].second;
			
			// cout<<i<<" "<<j<<endl;
			
			if(sms[i][j] != 'X'){
				flag = false;
				break;
			}
			
			sms[i][j] = s[iPalabra];
			iPalabra++;
		}	
	}
	
	// cout<<"cuatro "<<flag<<endl;
	
	if(flag){
		rta = "";
		// cout<<endl;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				// cout<<sms[i][j];
				if(sms[i][j] == 'X'){
					flag = false;
					break;
				}
				rta += sms[i][j];
			}
			// cout<<endl;
		}
	}
 
	if(flag){
		cout<<rta<<"\n";
	}else{
		cout<<"invalid grille\n";
	}
 
}

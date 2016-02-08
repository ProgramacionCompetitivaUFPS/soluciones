/********************************************************************
 * Ejercicio: Coding Contest Creation                           	*
 * Url: https://www.facebook.com/hackercup/problem/798506286925018/ *
 * Lenguaje: c++                                                    *
 * Autor: Melissa Delgado                                           *
 * Fecha: 08-02-2016                                                * 
 *******************************************************************/#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    ifstream cin("p1.txt");
    ofstream cout("salida.txt");
    
    int tc, i, rta, j, n, p, aux, cont;
    int problems[100005];
    cin>>tc;

    i=1;
    while(i<=tc){
    	cin>>n;
    	rta=0;
    	cin>>problems[0];
    	p=1;

    	for(j=1; j<n; j++){
    		//cout<<j<<" "<<p<<" "<<rta<<endl;
			cin>>problems[j];

			if(p>0){
				if(problems[j]-problems[j-1]>10){
					aux=problems[j-1];
					cont=0;
					while(p<4 && problems[j]-aux>10){
						rta++;
						p++;
						aux+=10;
					}
					
					if(p<4 && problems[j]-aux<=10){
						p++;
					}else{
						p=1;
					}
				}else if(problems[j]-problems[j-1]<=0){
					rta+=4-p;
					p=1;
				}else{
					p++;
				}
			}else{
				p++;
			}    	
			
			if(p==4){
				p=0;
			}
    	}
		
		if(p>0 && p<4){
			rta+=(4-p);	
		}
    	

    	cout<<"Case #"<<i<<": "<<rta<<endl;
    	i++;
    }


    
    
    return 0;
}

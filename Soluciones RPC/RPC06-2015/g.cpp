/********************************************************************
 * Ejercicio: More or Less Accurate                                 *
 * Url: https://acm.javeriana.edu.co/maratones/2015/06              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro )                                                  *
 *******************************************************************/

#include <iostream>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    
    bool cambio, flag, flag2;
    string s;
    int i;

    while(cin>>s){
    	
    	if(s[s.size()-1]=='0'){
    		s[s.size()-1]='1';
    	}else{
	    	cambio=true;
	    	flag=true;
	    	flag2=true;
	
	    	for(i=s.size()-1; i>=0; i--, flag=!flag){
	 			if((s[i]=='1' && cambio) || (s[i]=='0' && !cambio)){
	    			s[i]='0';
	    		}else{
	    			s[i]='1';
	    		}
		
	    		if((s[i]=='0' && !flag) || (s[i]=='1' && flag)){
	    			cambio=false;
	    			break;
	    		}
	    	}

	    	while(cambio){
	    		cout<<"1";
	    		if(flag){
	    			cambio=false;
	    			flag2=false;
	    		}
	    		flag=!flag;
	    	}
	
    	}
    	
    	
    	i = 0;
    	if(flag2){
        for(;i<s.size();i++){
            if(s[i]!='0')break;
        }
    	}
        if(i==s.size()){
        	cout<<"0";
        }
        for(;i<s.size();i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
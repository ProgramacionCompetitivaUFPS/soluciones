/********************************************************************
 * Ejercicio: Toby and the Graph                                    *
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
    unsigned long long t;
    int i;
    int src, dest, x, y, islas;
    int subset[10001];
	int n, m, rta;
	set<int> subs;
    set<int>::iterator it, it2;
    
    cin>>t;
    while(t>0){
    	cin>>n>>m;
    	subs.clear();
    	memset(subset, -1, (n+1)*sizeof(int));
    	islas=n;
    	while(m>0){
    		cin>>src>>dest;
    		x=subset[src];
    		y=subset[dest];
    		if(x==-1 && y==-1){
    			subset[src]=src;
    			subset[dest]=src;
    			subs.insert(src);
    			islas-=2;
    		}else if(x==-1 && y!=-1){
    			subset[src]=dest;
    			islas--;
    		}else if(x!=-1 && y==-1){
    			subset[dest]=src;
    			islas--;
    		}else{
    			it=subs.find(x);
    			it2=subs.find(y);
    			if(it!=subs.end() && it2!=subs.end() && x!=y){
    				subs.erase(it);
    			}
    		}
    		m--;
    	}
    	islas+=subs.size();
    	rta=(islas*(islas-1))/2;
    	cout<<rta<<endl;
    	t--;
    }
}
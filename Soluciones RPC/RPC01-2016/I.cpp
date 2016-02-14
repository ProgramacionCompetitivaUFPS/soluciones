/********************************************************************
 * Ejercicio: I Rummikub                                 			*
 * Url: https://acm.javeriana.edu.co/maratones/2016/01/            	*
 * Lenguaje: c++	                                                *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -   	*
 * Gerson Lázaro                                                    *
 * Fecha: 13-02-2016                                              	*
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc, m, n, cont;
	char x;
	
	map<int, set<char> > groups;
	map<char, set<int> > runs;
	
	set<int> aux;
	
	bool flag;
	
	scanf("%d", &tc);
	
	while(tc){
		scanf("%d", &m);
		
		groups.clear();
		runs.clear();
		
		flag=false;
		
		while(m>0){
			scanf("%d%c", &n, &x);
			groups[n].insert(x);
			
			if(groups[n].size()>=3)	flag=true;
			
			runs[x].insert(n);
			m--;
		}
		
		if(!flag){
			map<char, set<int> >::iterator it;
			set<int>::iterator sit;
			for(it=runs.begin(); it!=runs.end(); it++){
				aux=it->second;
				sit=aux.begin();
				n=*sit;
				cont=1;
				sit++;
				
				while(sit!=aux.end()){
					if(*sit==n+1){
						cont++;
						if(cont==3){
							flag=true;
							break;
						}
					}else{
						cont=1;
					}
					n=*sit;
					sit++;
				}
				
				if(flag)	break;
			}
		}
		
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
		
		tc--;
	}
	
	return 0;
}
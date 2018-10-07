/****************************************
 * Ejercicio: Texting with Grandma	    *
 * Url: https://uva.onlinejudge.org/	*
 * Número: 12947 						*
 * Lenguaje: c++                        *
 * Autor: Angie Melissa Delgado         *
 * Fecha: 08-11-2015                    *                     
 ****************************************/

#include <bits/stdc++.h>

using namespace std;

int main(){
	string line;
	int a, n, cont, i, tc, caso;
	map<int,int> mapa;
	vector<int> text;
	bool flag, rta;
	set<int> ady[100007];
	caso=0;

	while(getline(cin,line)){
		if(caso>0){
			cout<<"*\n";
		}
		istringstream c;
		mapa.clear();
		text.clear();
		c.str(line);
		n=0;
		while(c >> a){
			mapa[a]++;
			text.push_back(a);
			ady[n].clear();
			n++;
		}
		tc=n;
		ady[n].clear();
		ady[n+1].clear();
		ady[n+2].clear();
		n+=2;

		i=0;
		priority_queue<int, vector<int>, greater<int> > pq;
		rta=true;
		for(cont=0; i<tc; cont++){
			flag=false;
			if(text[i]>=n){
				rta=false;
				break;
			}
			if(!pq.empty()){
				if(pq.top()<=cont){
					ady[text[i]].insert(pq.top());
					ady[pq.top()].insert(text[i]);
					
					if(pq.top()<cont){
						cont--;
					}
					pq.pop();
					
					mapa[text[i]]--;
					if(mapa[text[i]]==0){
						pq.push(text[i]);
					}
					i++;
					flag=true;
				}
			}

			if(!flag && mapa[cont]==0){
				ady[text[i]].insert(cont);
				ady[cont].insert(text[i]);
				
				mapa[text[i]]--;
				if(mapa[text[i]]==0){
					pq.push(text[i]);
				}
				i++;
			}

		}

		if(rta){
			set<int> aux;
			while(cont<n){
				aux.insert(cont);
				cont++;
			}

			while(!pq.empty()){
				aux.insert(pq.top());
				pq.pop();
			}
			
			if(aux.size()==2){
				set<int>::iterator it;
				it=aux.begin();
				i=*it;
				it++;
				a=*it;
				ady[a].insert(i);
				ady[i].insert(a);
			}else{
				rta=false;
			}
		}

		if(rta){
			cout<<n<<"\n";
			for(i=0; i<n; i++){
				set<int>::iterator it;
				it=ady[i].begin();
				while(it!=ady[i].end()){
					cout<<*it;
					it++;
					if(it!=ady[i].end()){
						cout<<" ";
					}
				}
				cout<<"\n";
			}
		}else{
			cout<<"impossible\n";
		}
		caso++;
	}
}

/********************************************************************
 * Ejercicio:  G - Texting with Grandma		                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 07-05-2016                                                *
 *******************************************************************/

 #include <bits/stdc++.h>

using namespace std;

vector<int> sms;
map<int,int> leaves;
vector<int> ady[100010];
int tam;

class cmp{
	public:
		bool operator()(int n1, int n2){
			if(n1>n2)
				return true;
			else 
				return false;
		}
};

void init(){
	int i;
	for(i=0; i<tam; i++){
		ady[i].clear();
	}
}

void print(){
	cout<<tam<<"\n";
	int i, j;
	for(i=0; i<tam; i++){
		sort(ady[i].begin(), ady[i].end());
		for(j=0; j<ady[i].size(); j++){
			if(j==0){
				cout<<ady[i][j];
			}else{
				cout<<" "<<ady[i][j];
			}
		}
		cout<<"\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	string s;
	int i, a, x;
	bool rta;
	bool imprimio=false;
	
	for(getline(cin, s); cin; getline(cin, s)){
		if(imprimio){
			cout<<"*\n";
		}
		imprimio=true;
		istringstream inp;
		inp.str(s);
		priority_queue<int, vector<int>, cmp> pq;
		rta=true;
		sms.clear();
		leaves.clear();
		i=0;
		
		while(inp>>a){
			pq.push(i);
			leaves[a]++;
			sms.push_back(a);
			i++;
		}
		
		pq.push(i);
		pq.push(i+1);
		tam=i+2;
		
		init();
		
		for(i=0; i<sms.size(); i++){
			a=sms[i];
			if(a>=tam){
				rta=false;
				break;
			}
			
			x = pq.top();
			pq.pop();
			
			while(leaves[x] > 0){
				if(pq.size()==0){
					rta=false;
					break;
				}
				x=pq.top();
				pq.pop();
			}
			ady[x].push_back(a);
			ady[a].push_back(x);
			
			leaves[a]--;
			if(leaves[a]==0 && (pq.size()==0 || (pq.size()>0 && a<pq.top())) ){
				pq.push(a);
			}
		}
		
		if(pq.size() == 2){
			a=pq.top();
			pq.pop();
			x=pq.top();
			pq.pop();
			
			ady[x].push_back(a);
			ady[a].push_back(x);
		}else{
			rta=false;
		}
		
		if(rta){
			print();
		}else{
			cout<<"impossible\n";
		}
	}
	return 0;
}
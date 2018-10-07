/********************************************************************
 * Ejercicio:  G - Up Go the Ultras                                 *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 22-10-2016                                                *
 *******************************************************************/

 #include <bits/stdc++.h>

using namespace std;

vector<int> h;
map<int, int> prom;

struct seg_tree{ 
	vector<int> st; //pares, impares
	vector<int> data;
	int N;

	seg_tree(int _N, vector<int> &_data){
		data = _data;
		N = _N;
		st.resize(4*N);
		init(1, 1, N); //nodo, inicio, fin
	}

	int left(int L){
		return L << 1; 
	}

	int right(int R){
		return R << 1 | 1;
	}

	void init(int node, int L, int R){
		if(L==R){
			st[node] = data[L];
		}else{
			int mid;
			int p1, p2;
			mid = (L+R)/2;
			init(left(node), L, mid);
			init(right(node), mid+1, R);
			p1 = st[left(node)];
			p2 = st[right(node)];
			
			st[node] = min(p1, p2);
		}
	}

	int query(int node, int L, int R, int i, int j){
		if(i > R || j < L){
			return -1;
		}

		if(L >= i && R <= j){
			return st[node];
		}
	
		int mid, p1, p2;

		mid = (L+R) >> 1;
		p1=query(left(node), L, mid, i, j);
		p2=query(right(node), mid+1, R, i, j);

		if( p1 == -1)	return p2;
		if( p2 == -1)	return p1;

		return min(p1, p2);

	}

	int query(int i, int j){
		return query(1, 1, N, i, j);
	}
};

int main(){
	int n, i, aux, ant, sig, d, ind;
	bool flag;
	vector<int> indices;
	map<int, int>::iterator it;
	while(cin >> n){
		h.clear();
		prom.clear();
		h.push_back(0);
		indices.clear();
		ant = 0;
		d = 0;
		for(i = 1; i <= n; i++){
			cin >> aux;
			h.push_back( aux );
			if( aux > ant ){
				ant = aux;
				indices.clear();
				indices.push_back(i);
			}else if( aux == ant){
				indices.push_back(i);
			}
		}
		
		for(i = 0; i < indices.size(); i++){
			prom[ indices[i] ]=300000;
		}
		
		
		seg_tree tree(n+1, h);
		
		//Buscar picos hacia la derecha
		stack<int> q;
		ant = h[1];
		for(i = 2; i <= n; i++){
			sig = h[i];
			if( sig >= ant ){
				while( !q.empty() ){
					ind = q.top();
					aux = h[ind];
					q.pop();
					//cout<<ind<<" "<<aux<<" "<<i<<" "<<sig<<" "<<endl;
					if( sig > aux ){
						d = tree.query(ind, i);
						//cout<<aux-d<<endl;
						prom[ind] = aux-d;
					}else{
						q.push(ind);
						break;
					}
				}
				q.push(i);
			}
			ant = sig;
		}
	
		//Buscar picos hacia la izq
		stack<int> qq;
		ant = h[n];
		for(i = n-1; i > 0; i--){
			sig = h[i];
			if( sig >= ant ){
				while( !qq.empty() ){
					ind = qq.top();
					aux = h[ind];
					qq.pop();
					//cout<<ind<<" "<<aux<<" "<<i<<" "<<sig<<" "<<endl;
					if( sig > aux ){
						d = tree.query(i, ind);
						//cout<<d<<endl;
						//cout<<ind<<" "<< aux-d <<endl;
						prom[ind] = min( prom[ind], aux-d );
					}else{
						qq.push(ind);
						break;
					}
				}
				qq.push(i);
			}
			ant = sig;
		}
		
		
		//respuesta
		it = prom.begin();
		flag = false;
		while( it != prom.end() ){
			//cout << it-> first <<" "<<it->second<<endl;
			if( it-> second >= 150000){
				if(flag){
					cout<<" ";
				}else{
					flag = true;
				}
				cout << it->first;
			}
			it++;
		}
		cout << "\n";
	}
	return 0;
}
/********************************************************************
 * Ejercicio:  H - Potentiometers			                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 04-06-2016                                                *
 *******************************************************************/

 #include <bits/stdc++.h>

using namespace std;

struct seg_tree{
	vector<int> st;
	int N;
	
	seg_tree(int n){
		st.resize(n*4+10);
		// lazy.resize(n*4+10);
	}
	
	int left(int L){
		return L << 1; 
	}

	int right(int R){
		return R << 1 | 1;
	}
	
	void init(vector<int> &resistencias, int node, int L, int R){
		N = resistencias.size() -1 ;
		
		if(L==R){
			st[node] = resistencias[L];
			return;
		}
		
		int p1, p2, mid;
		mid = (L + R) / 2;
		p1 = node * 2;
		p2 = p1 + 1;
		
		init( resistencias, p1, L, mid);
		init( resistencias, p2, mid+1, R);
		
		st[node] = st[p1] + st [p2];
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
		p1 = query( left(node), L, mid, i, j);
		p2 = query( right(node), mid+1, R, i, j);

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;

		return p1+p2;
	}

	int query(int i, int j){
		return query(1, 1, N, i, j);
	}

	int update(int node, int L, int R, int i, int value){
		if(i < L || i > R){
			return st[node];
		}

		if(L == R){
			return st[node] = value;
		}else{
			int mid = (L+R) >> 1;
			int p1 = update( left(node), L, mid, i, value );
			int p2 = update( right(node), mid+1, R, i, value );

			st[node] = p1+p2;
			
			return st[node];
		}
	}

	void update(int i, int value){
		update(1, 1, N, i, value);
	}
	
};

seg_tree tree(200010);

int main() {
	int n, a, x, r, tc, y;
	string s;
	vector<int> resistencias;
	tc = 1;
	cin>>n;
	
	while(n!=0){
		if(tc>1){
			cout<<"\n";
		}
		
		cout<<"Case "<<tc<<":\n";
		tc++;
		
		resistencias.clear();
		resistencias.push_back(0);
		
		while(n>0){
			cin>>a;
			resistencias.push_back(a);
			n--;
		}
		
		tree.init(resistencias, 1, 1, resistencias.size() - 1);
		cin>>s;
		while(s != "END"){
			if(s == "S"){
				cin>>x>>r;
				tree.update(x, r);
			}else{
				cin>>x>>y;
				cout<<tree.query(x, y)<<"\n";
			}
			cin>>s;
		}
		cin>>n;
	}
	return 0;
}
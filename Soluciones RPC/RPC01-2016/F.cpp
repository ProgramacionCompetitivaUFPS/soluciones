/********************************************************************
 * Ejercicio: F Manhattan Power Failure                   			*
 * Url: https://acm.javeriana.edu.co/maratones/2016/01/            	*
 * Lenguaje: c++	                                                *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -   	*
 * Gerson Lázaro                                                    *
 * Fecha: 13-02-2016                                              	*
 *******************************************************************/

 #include <bits/stdc++.h>

using namespace std;

vector<int> ady[10010];
int est[10010];
int parent[10010];
int rank[10010]; 
int v;
map<int, bool> roots;

void init(){
	int i;
	roots.clear();
	for(i=0; i<v; i++){
		ady[i].empty();
		parent[i]=i;
        rank[i]=0;
		est[i]=0; //o no energia, 1 si energia
		roots[i] = true;
	}
}

int find(int i){
    if(parent[i]!=i){
    	if(est[i]==1)	est[parent[i]]=1;
        parent[i]=find(parent[i]);
    }
    return parent[i];
}

void unionFind(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
 	
 	if(est[yroot]==1)	est[xroot]=1;
 	if(est[xroot]==1)	est[yroot]=1;
    
    // (Union by rank)
    if (rank[xroot] < rank[yroot]){
        parent[xroot] = yroot;
        roots[xroot] = false;
        roots[yroot] = true;
    }else if (rank[xroot] > rank[yroot]){
        parent[yroot] = xroot;
        roots[yroot] = false;
        roots[xroot] = true;
    }else{
        parent[yroot] = xroot;
        rank[xroot]++;
        roots[yroot] = false;
        roots[xroot] = true;
    }
}


int main() {
	int tc, n, m, p, c, s, d, x, y, rta;
	char dir;
	cin>>tc;
	
	while(tc){
		cin>>n>>m>>p>>c;
		v=n*m;
		init();
		
		while(p>0){
			cin>>s>>d;
			s=(s*m)+d;
			est[s]=1;
			p--;
		}

		while(c>0){
			cin>>s>>d>>dir;
			s=(s*m)+d;
			if(dir=='R'){
				d=s+m;
			}else{
				d=s+1;
			}
			
			x=find(s);
	        y=find(d);
			
	        if(x!=y){
	            unionFind(x, y);
        	}
			c--;
		}
		
		rta=0;
		map<int, bool>::iterator it;

		for(it=roots.begin(); it!=roots.end(); it++){
			if(it->second && est[it->first]==0){
				rta++;
			}
		}
		
		cout<<rta<<"\n";
		
		tc--;
	}
	
	return 0;
}
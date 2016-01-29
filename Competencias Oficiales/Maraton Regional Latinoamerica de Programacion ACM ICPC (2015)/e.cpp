#include <bits/stdc++.h>

using namespace std;

int n, d, p, b, cantd, cantp, precioComponente;
pair<int,int> congress[210]; //partido D, partido P
int price[210]; //aqui guardo el precio de la COMPONENTE
int memoD[210][10010]; //partido D
int memoP[210][10010]; //partido P
vector<int> ady[210];
int pc[210]; //aqui guardo el precio de cada congresista
bool vis[210];

void init(){
	int i, j;
	pair<int,int> x=make_pair(0,0);
	pair<int,int> y=make_pair(-1,-1);

	for(i=0; i<=n; i++){
		vis[i]=false;
		pc[i]=0;
		congress[i]=x;
		ady[i].clear();
		price[i]=0;
	}
	
	memset(memoD, -1, sizeof(memoD));
	memset(memoP, -1, sizeof(memoP));
}

void dfs(int src){
	int i, dest;
	vis[src]=true;
	precioComponente+=pc[src];
	if(src>d){
		cantp++;
	}else{
		cantd++;
	}

	for(i=0; i<ady[src].size(); i++){
		dest=ady[src][i];
		if(!vis[dest]){
			dfs(dest);
		}
	}

}

void findComponents(){
	int i, j;
	j=0;
	for(i=1; i<=n; i++){
		cantd=cantp=precioComponente=0;
		if(!vis[i]){
			dfs(i);
			price[j]=precioComponente;
			congress[j]=make_pair(cantd, cantp);
			j++;
		}
	}
	n=j;
}

pair<int,int> knapsack(int id, int bullet){

	if(id==n || bullet==0){
		return make_pair(0,0);
	}

	if(memoD[id][bullet] != -1 && memoP[id][bullet] != -1){
		return make_pair(memoD[id][bullet], memoP[id][bullet]);
	}
	
	pair<int,int> aux, aux2;

	if(price[id] > bullet){
		aux=knapsack(id+1, bullet);
		memoD[id][bullet] = aux.first;
		memoP[id][bullet] = aux.second;
	}else{
		aux=knapsack(id+1, bullet);
		aux2=knapsack(id+1, bullet-price[id]);

		memoD[id][bullet]= max( aux.first,
								(congress[id].second-congress[id].first)+aux2.first);

		memoP[id][bullet]= max( aux.second,
								(congress[id].first-congress[id].second)+aux2.second);
	}
	
	return make_pair(memoD[id][bullet], memoP[id][bullet]);
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int tc, r, i, aux, src, dest;
	pair<int,int> rta;
	while(cin>>d){
		cin>>p;
		n=d+p;
		cin>>r>>b;
		init();
		for(i=1; i<=n; i++){
			cin>>pc[i];
		}

		while(r>0){
			cin>>src>>dest;
			dest+=d;
			ady[src].push_back(dest);
			ady[dest].push_back(src);
			r--;
		}

		findComponents();
		rta=knapsack(0, b);
		cout<<d+rta.first<<" "<<p+rta.second<<"\n";
	}
}
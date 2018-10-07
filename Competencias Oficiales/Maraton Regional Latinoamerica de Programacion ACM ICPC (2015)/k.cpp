/****************************************************************************************************
 * Ejercicio: Keep it energized                                 									*
 * Url: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=702	*
 * Lenguaje: c++	                                              								  	*
 * Autor: Candelaria (Melissa Delgado - Cristhian León -  Gerson Lázaro)                          	*                        *
 * Fecha: 14-11-2015                                                								*
 ***************************************************************************************************/

#include <bits/stdc++.h>
#define Node pair<int,int>

using namespace std;

int v;
vector<Node> ady[100005];
int marked[100005];
long long dis[100005];
int needed[100005];
int strength[100005];
int cost[1000005];

class cmp
{
public:
    bool operator()(Node n1,Node n2)
    {
      if(n1.second>n2.second)
      return true;
      else
      return false;
    }
};

void init(){
    for(int j=0; j<=v; j++){
        ady[j].clear();
        marked[j]=0;
 		needed[j]=0;
 		strength[j]=0;
 		cost[j]=0;
        dis[j]=-1;
    }
}

void dijkstra(int s){
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push(Node(s, 0));//se inserta a la cola el nodo Inicial.
    dis[s]=0;
    int actual, j, adjacent;
    long long weight;

    while(!pq.empty()){
        actual=pq.top().first;
        pq.pop();
        if(marked[actual]==0){
            marked[actual]=1;
            for(j=0; j<ady[actual].size(); j++){
                adjacent=ady[actual][j].first;
                weight=ady[actual][j].second;
                if(marked[adjacent]==0){
                    if(dis[adjacent]==-1 || dis[adjacent]>dis[actual]+weight){
                         dis[adjacent]=dis[actual]+weight;
                         pq.push(Node(adjacent, dis[adjacent]));
                     }
                }
            }
        }
    }
}

void build(){
	int i, e, aux, j;
	ady[0].push_back(Node(1,0));
	for(i=1; i<v; i++){
		aux=0;
		e=strength[i];
		for(j=i; j<v-1; j++){
			aux+=needed[j];
			if(e>=aux){
				ady[i].push_back(Node(j+1, cost[i]));
			}else{
				break;
			}
		}
	}
}

int main(){
	int i, n, m, aux;
	while(cin>>n){
		cin>>m;
		v=n+2;
		init();

		for(i=1; i<=n; i++){
			cin>>needed[i];
		}

		for(i=0; i<m; i++){
			cin>>aux;
			cin>>strength[aux]>>cost[aux];
		}

		build();
		dijkstra(0);
		cout<<dis[v-1]<<"\n";
	}
}
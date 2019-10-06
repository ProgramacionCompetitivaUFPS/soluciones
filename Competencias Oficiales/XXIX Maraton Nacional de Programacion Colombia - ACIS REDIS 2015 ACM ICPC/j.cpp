#include <bits/stdc++.h>
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x) 0
#endif
#define pb push_back
#define F first
#define S second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (1<<30)

const int MAX = 30; //Cantidad maxima de nodos
vector<int> g[MAX], ties; //Matriz de adyacencia
ll votes[MAX][MAX];
bitset<MAX> vis;
int n, m, c, cont; //Cantidad de nodos y aristas

void init() {
    cont = 0;
    ties.clear();
    vis = 0;
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        for(int j = 0; j <= n; j++) {
            votes[i][j] = 0;
        }
    }
}


void calculate(int x, string cad){
    int a, b;
    for (int i = 0; i < n; i++) {
        a = cad[i]-'a';
        for (int j = i+1; j < n; j++) {
            b = cad[j]-'a';
            votes[a][b]+=x;
        }
    }
}


void make_graph(){
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(votes[i][j] > votes[j][i])g[i].pb(j);
            else if(votes[i][j] < votes[j][i])g[j].pb(i);
            else{
                if(c == i)ties.pb(j);
                if(c == j)ties.pb(i);
            }
        }
    }
}

void dfs(int u){
    cont++;
    vis[u] = true;
    for(auto x: g[u]){
        if(!vis[x])dfs(x);
    }
}


int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    char can;
    string s;

    while(cin >> n >> m >> can){
        c = can-'a';
        init();
        for (int i = 0; i < m; i++) {
            cin >> x >> s;
            calculate(x, s);
        }

        make_graph();

        dfs(c);

        for(auto x: ties){
            if(!vis[x])dfs(x);
        }

        if(cont == n)cout << "Y\n";
        else cout << "N\n";

    }

}

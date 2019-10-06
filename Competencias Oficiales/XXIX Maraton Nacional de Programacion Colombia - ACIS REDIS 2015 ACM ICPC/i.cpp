#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;

#define debug(x) cout << #x << "=" << x << endl;
#define pb push_back
#define F first
#define S second

const int inf = (1<<29);
const int MAX = 302;
int n, m, k, u, v, c, t, x;
map<string, int> mapa;
vector<edge> g[MAX];
pii dist[MAX][MAX]; // nodo, distancia (costo, tiempo)


void algo(){
    for(auto ed: g[u]){
        v = ed.F;
        dist[v][0] = min(dist[v][0], ed.S);
    }
    //distancia de cada nodo con i pasos
    for(int i = 1; i < MAX; i++){
        for (int u = 0; u < n; u++) {
            for(auto ed: g[u]){
                v = ed.F;
                int d = dist[u][i-1].F;
                t = dist[u][i-1].S;
                if(dist[v][i].F > d+ed.S.F){
                    dist[v][i] = {d+ed.S.F, t+ed.S.S};
                }else if(dist[v][i].F == d+ed.S.F){
                    if(dist[v][i].S > t+ed.S.S) dist[v][i].S = t+ed.S.S;
                }
            }
        }
    }

    //distancia minima 0 <= pasos <= k
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < MAX; j++) {
            dist[i][j] = min(dist[i][j], dist[i][j-1]);
        }
    }
}

void init(){
    mapa.clear();
    for(int i = 0; i <= n; i++){
        g[i].clear();
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = {inf, inf};
        }
    }
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, ss;
    bool f = 0;
    while(cin >> n >> m >> k){
        if(f)cout << ".\n";
        f = true;
        init();
        for (int i = 0; i < n; i++) {
            cin >> s;
            mapa[s] = i;
        }
        for (int i = 0; i < m; i++) {
            cin >> s >> ss >> c >> t;
            u = mapa[s];
            v = mapa[ss];
            g[u].pb({v, {c, t}});
        }
        cin >> s;
        u = mapa[s];
        dist[u][0] = {0, 0};
        algo();
        u = mapa[s];
        for (int i = 0; i < k; i++) {
            cin >> ss >> x;
            v = mapa[ss];
            c = dist[v][x].F;
            t = dist[v][x].S;
            if(c == inf && t == inf)cout << "* *\n";
            else cout << c << " " << t << "\n";
        }
    }

}

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

#define INF (1<<29)

struct edge {
    int u, v, cap, flow, cost;
    int rem() { return cap - flow; }
};

const int MAX = 25; //Cantidad maxima total de nodos
vector<int> g[MAX]; //Lista de adyacencia
vector<edge> e; //Lista de aristas
bitset<MAX> in_queue; //Marca los nodos que estan en cola
int pre[MAX]; //Almacena el nodo anterior para construir las rutas
int dist[MAX]; //Almacena la distancia a cada nodo
int cap[MAX]; //Almacena el flujo que pasa por cada nodo
int N; //Cantidad total de nodos
int mncost, mxflow; //Costo minimo y Flujo maximo

void add_edge(int u, int v, int cap, int cost) {
    g[u].push_back(e.size());
    e.push_back({u, v, cap, 0, cost});
    g[v].push_back(e.size());
    e.push_back({v, u, 0, 0, -cost});
}

void flow(int s, int t) {
    in_queue = mxflow = mncost = 0;
    while (true) {
        fill(dist, dist+N, INF); dist[s] = 0;
        memset(cap, 0, sizeof(cap)); cap[s] = INF;
        memset(pre, -1, sizeof(pre)); pre[s] = 0;
        queue<int> q;
        q.push(s);
        in_queue[s] = true;

        while (q.size()) {
            int u = q.front(); q.pop();
            in_queue[u] = false;
            for (int i : g[u]) {
                edge &ed = e[i];
                int v = ed.v;
                if (ed.rem() && dist[v] > dist[u]+ed.cost) {
                    dist[v] = dist[u]+ed.cost;
                    cap[v] = min(cap[u], ed.rem());
                    pre[v] = i;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                    }
                }
            }
        }
        if (pre[t] == -1) break;
        mxflow += cap[t];
        mncost += cap[t] * dist[t];
        for(int v = t; v != s; v = e[pre[v]].u) {
            e[pre[v]].flow += cap[t];
            e[pre[v]^1].flow -= cap[t];
        }
    }
}

void init() {
    e.clear();
    for(int i = 0; i <= N; i++) {
        g[i].clear();
    }
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        N = n+2;
        init();
        for (int i = 1, w; i < n; i++) {
            cin >> w;
            add_edge(0, i, w, 0);
        }
        for (int i = 0, u, v, w, c; i < m; i++) {
            cin >> u >> v >> w >> c;
            add_edge(u, v, w, c);
            add_edge(v, u, w, c);
        }
        add_edge(n, N-1, INF, 0);
        flow(0, N-1);
        cout << mxflow << " " << mncost << endl;
    }
}

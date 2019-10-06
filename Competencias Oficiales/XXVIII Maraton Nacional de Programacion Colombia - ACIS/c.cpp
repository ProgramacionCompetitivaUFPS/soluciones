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

struct edge {
	int u, v, comp;
	bool bridge;
};

const int MAX = 1005;
vector<int> g[MAX];
vector<edge> e;
int low[MAX], num[MAX], cont;
set<pii> bridges;
int N, M;

void add_edge(int u, int v){
	g[u].push_back(e.size());
	g[v].push_back(e.size());
	e.push_back({u, v, -1, false});
}

void dfs(int u, int p = -1) {
	low[u] = num[u] = cont++;
	for (int i : g[u]) {
		edge &ed = e[i];
		int v = ed.u^ed.v^u;
		if (num[v] == -1) {
			dfs(v, i);
			if (low[v] > num[u]) {
				ed.bridge = true; //bridge
				bridges.insert(minmax(ed.u, ed.v));
			}
			low[u] = min(low[u], low[v]);
		} else if (i != p && num[v] < num[u]) {
			low[u] = min(low[u], num[v]);
		}
	}
}

void init() {
	cont = 0;
	e.clear();
	bridges.clear();
	for (int i = 0; i <= N; i++) {
		g[i].clear();
		num[i] = -1;
	}
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N >> M, N+M) {
        init();
        for (int i = 0, u, v; i < M; i++) {
            cin >> u >> v;
            add_edge(u, v);
        }
        dfs(0);
        cout << SZ(bridges);
        for (auto x : bridges) {
            cout << " " << x.F << " " << x.S;
        }
        cout << '\n';
    }
}

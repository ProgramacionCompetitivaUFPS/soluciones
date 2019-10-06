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

const int MAX = 400005;
vector<int> g[MAX];
vector<int> tour;
int sz[MAX];
int n, m;

bool isnum(char c){
    if(c >= '0' && c <= '9')return true;
    return false;
}

int construir(string s){
    stack<int> node;
    int par = 0;
    int i = 0;
    int num = 0;
    while(i < s.size()){
        if(s[i] == '('){
            par++;
        }else if(s[i] == ')'){
            int h1 = node.top(); node.pop();
            int p = node.top(); node.pop();
            int h2 = node.top(); node.pop();
            g[p].pb(h2);
            g[p].pb(h1);
            node.push(p);
        }else if(isnum(s[i])){
            while(i+1 < s.size() && isnum(s[i+1])){
               i++;
            }
            node.push(num++);
        }else{
            node.push(num++);
        }
        i++;
    }
    n = num;
    return node.top();
}

void dfs(int u) {
    sz[u] = 1;
    for (auto v : g[u]) {
        dfs(v);
        sz[u] += sz[v];
    }
    tour.pb(sz[u]);
}

void init(){
    memset(sz, 0, sizeof(sz));
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

vector<int> z_function(vector<int> &s) {
	vector<int> z(SZ(s));
	for (int i = 1, x = 0, y = 0; i < SZ(s); i++) {
		z[i] = max(0, min(z[i-x], y-i+1));
		while (i+z[i] < SZ(s) && s[z[i]] == s[i+z[i]]) {
			x = i; y = i+z[i]; z[i]++;
		}
	}
	return z;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int root;
    string s, t;
    while(cin >> s >> t){
        init();
        tour.clear();
        root = construir(s);
        dfs(root);

        int N = n;
        tour.pb(-1);

        init();
        root = construir(t);
        dfs(root);

        vector<int> z = z_function(tour);
        int ans = 0;
        for (int i = N+1; i < SZ(z); i++) {
            if (z[i] == N) ans++;
        }
        cout << ans << '\n';
    }
}

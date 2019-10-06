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

const int MAX = 100005;
int cont[MAX];
priority_queue<int, vector<int>, greater<int>> hojas;
vector<int> num;
vector<int> g[MAX];
int n;

void init(){
    while(hojas.size())hojas.pop();
    num.clear();
    for (int i = 0; i <= n; i++) {
        cont[i] = 0;
        g[i].clear();
    }
}


vector<string> split(string s) {
    vector<string> v;
    istringstream iss(s);
    string sub;
    while (iss >> sub) {
        v.push_back(sub);
    }
    return v;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;


    bool f = false;

    while(getline(cin, s)){
        if(f)cout << "*\n";
        f = true;

        vector<string> vec = split(s);
        n = vec.size()+2;
        int mx = -1;
        init();
        for (int i = 0; i < vec.size(); i++) {
            int x = atoi(vec[i].data());
            num.pb(x);
            cont[x]++;
            mx = max(mx, x);
        }

        for (int i = 0; i < n; i++) {
            if(!cont[i])hojas.push(i);
        }

        for(auto x: num){
            int h = hojas.top(); hojas.pop();
            g[x].pb(h);
            g[h].pb(x);
            cont[x]--;
            if(!cont[x])hojas.push(x);
        }

        if(hojas.size() != 2)cout << "impossible\n";
        else{
            int x = hojas.top();
            hojas.pop();
            int y = hojas.top();
            hojas.pop();
            g[x].pb(y);
            g[y].pb(x);
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                sort(g[i].begin(), g[i].end());
                for(int j = 0; j < g[i].size(); j++){
                    cout << g[i][j] << " \n"[j == SZ(g[i])-1];
                }
            }

        }



    }

}

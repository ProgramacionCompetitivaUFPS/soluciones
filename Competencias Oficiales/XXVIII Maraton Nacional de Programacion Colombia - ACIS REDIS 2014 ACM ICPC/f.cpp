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

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;

    while(cin >> n){
        priority_queue<int> node;
        for (int i = 0; i < n; i++) {
            cin >> x;
            node.push(x);
        }
        bool f = true;

        while(node.size()){
            vector<int> vec;
            int x = node.top();
            node.pop();
            if(node.size() < x){
                f = false;
                break;
            }
            for (int i = 0; i < x; i++) {
                int y = node.top();
                node.pop();
                if(y-1 > 0)vec.pb(y-1);
            }
            for(auto y: vec){
                node.push(y);
            }
        }


        if(f)cout << "1\n";
        else cout << "0\n";

    }

}

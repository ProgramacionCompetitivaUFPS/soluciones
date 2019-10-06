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
int num[MAX];
vector<int> len;

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    while(cin >> n){
        len.clear();
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if(num[i] < num[i-1]){
                len.pb(cnt);
                cnt = 1;
            }else{
                cnt++;
            }
        }
        len.pb(cnt);
        int mx = len[0];
        for(int i = 1; i < len.size(); i++){
            mx = max(mx, (len[i]+len[i-1]));
        }

        cout << mx << "\n";

    }

}

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

pii mult(pii a, pii b){
    return {a.F*b.F - a.S*b.S, a.F*b.S + a.S*b.F};
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    pii fac[31];
    fac[0] = {1, 0};
    fac[1] = {-1, 1};
  //  cout << "FACS" << endl;
    for(int i = 2; i <= 30; i++){
        fac[i] = mult(fac[i - 1], fac[1]);
    //    cout << i << ": " << fac[i].S
    }
   // cout << "END" << endl;
    int n;
    while(cin >> n){
        if(n == 0) cout << 0 << " " << 0 << '\n';
        else{
            pii ans = {0, 0};
            int LOG = floor(log2(n)) + 1;
            for(int i = 0; i <= LOG; i++){
                if(n & (1<<i)){
                    ans.F += fac[i].F;
                    ans.S += fac[i].S;
                }
            }
            cout << ans.F << " " << ans.S << '\n';
        }
    }


}

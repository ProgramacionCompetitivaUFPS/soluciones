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

const int MAX = 10005;

string a, b;
int A[MAX], B[MAX];
double p[3];
double dp[MAX][3];
int N;

int wining(int a, int b){
    if(b - a == 1 || a - b == 2) return 1;
    if(a - b == 1 || b - a == 2) return 2;
    return 0;
}

double f(int i, int win, int prev, int sum){
    //if(i == N){cout << sum << endl; return sum;} //return sum;
    if(i == N) return 0;
    double &ans = dp[i][win];
    if(ans != -1) return ans;
    ans = 0;
    //double ans = 0;
    if(!win){
        int winer0 = wining(0, B[i]);
        int winer1 = wining(1, B[i]);
        int winer2 = wining(2, B[i]);

        int aux0 = winer0 > 1 ? -1 : winer0;
        int aux1 = winer1 > 1 ? -1 : winer1;
        int aux2 = winer2 > 1 ? -1 : winer2;

        ans += p[0]*(f(i + 1, winer0, 0, sum + aux0) + aux0);
        ans += p[1]*(f(i + 1, winer1, 1, sum + aux1) + aux1);
        ans += p[2]*(f(i + 1, winer2, 2, sum + aux2) + aux2);

    }else if(win == 1){
        int auxi = ((prev - 1) + 3)%3;
        int winer = wining(auxi, B[i]);
        int aux = winer > 1 ? -1 : winer;
        ans += (f(i + 1, winer, auxi, sum + aux) + aux);
    }else{
        int auxi = ((B[i - 1] - 1) + 3)%3;
        int winer = wining(auxi, B[i]);
        int aux = winer > 1 ? -1 : winer;
        ans += (f(i + 1, winer, auxi, sum + aux) + aux);
    }

    return ans;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    double k;
    while (t--) {
        //memset(dp, -1, sizeof(dp));
        cin >> a >> b;
        N = a.size();
        for(int i = 0; i <= N; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = -1;

            }
        }
        cin >> k;
        p[0] = k/100.0; //roca
        cin >> k;
        p[2] = k/100.0; //papel
        cin >> k;
        p[1] = k/100.0; //tijera
        /*
        for(int i = 0; i < 3; i++){
            cin >> k;
            p[i] = k/100.0;
        }
        */
        int cont = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 'R') A[i] = 0;
            else if(a[i] == 'S') A[i] = 1;
            else if (a[i] == 'P') A[i] = 2;
            if(b[i] == 'R') B[i] = 0;
            else if(b[i] == 'S') B[i] = 1;
            else if (b[i] == 'P') B[i] = 2;

            if(B[i] - A[i] == 1 || A[i] - B[i] == 2) cont++;
            else if(A[i] - B[i] == 1 || B[i] - A[i] == 2) cont--;
        }
        cout << fixed << setprecision(4);
        double ans = f(0, 0, 0, 0);
        bool yes = ans > (double) cont;
        cout << cont << " " << ans << " ";
        if(yes) cout << "Y" << '\n';
        else cout << "N" << '\n';
    }
}

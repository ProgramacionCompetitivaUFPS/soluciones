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

const int MAX = 102;
long double X[MAX], Y[MAX], W[MAX];
int N;

long double fx(long double x){
	long double ans = 0;
	for(int i = 0; i < N; i++){
        ans += W[i]*(x - X[i])*(x - X[i]);
	}
	return ans;
}

long double ternary_x(double l, double r, int it){
    long double a = (2.0*l + r)/3.0;
    long double b = (l + 2.0*r)/3.0;
    if(it == 0){
      return fx(a);
    }
    if(fx(a) < fx(b)) return ternary_x(l, b, it-1);
    return ternary_x(a, r, it-1);
}


long double fy(long double y){
	long double ans = 0;
	for(int i = 0; i < N; i++){
        ans += W[i]*(y - Y[i])*(y - Y[i]);
	}
	return ans;
}

long double ternary_y(double l, double r, int it){
    long double a = (2.0*l + r)/3.0;
    long double b = (l + 2.0*r)/3.0;
    if(it == 0){
      return fy(a);
    }
    if(fy(a) < fy(b)) return ternary_y(l, b, it-1);
    return ternary_y(a, r, it-1);
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double mx, my, Mx, My;
    while(cin >> N){
        mx = 1005, my = 1005, Mx = -1005, My = -1005;
        for(int i = 0; i < N; i++){
            cin >> X[i] >> Y[i] >> W[i];
            mx = min(mx, X[i]);
            Mx = max(Mx, X[i]);
            my = min(my, Y[i]);
            My = max(My, Y[i]);
        }
        long double xx = ternary_x(mx, Mx, 50);
        long double yy = ternary_y(my, My, 50);
        long double ans = xx + yy;
        cout << fixed << setprecision(3) << ans << '\n';
    }
}

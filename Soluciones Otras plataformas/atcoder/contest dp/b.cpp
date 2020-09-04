/********************************************************************
 * Ejercicio: Frog 2                                                *
 * Url: https://atcoder.jp/contests/dp/tasks/dp_b                   *
 * Lenguaje: c++                                                    *
 * Autor: Sebastian Vega                                            *
 * Fecha: 27-08-2020                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 1e5 + 1, INF = 1e9;
int n, k, h[N], dp[N];

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) {
    dp[i] = INF;
    for (int j = 1; j <= k; j++) {
      if (i - j < 0) break;
      dp[i] = min(dp[i], abs(h[i] - h[i - j]) + dp[i - j]);
    }
    dp[i] = dp[i] == INF ? 0 : dp[i];
  }
  cout << dp[n - 1] << endl;
  return 0;
}
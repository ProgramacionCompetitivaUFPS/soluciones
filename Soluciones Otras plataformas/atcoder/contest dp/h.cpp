/********************************************************************
 * Ejercicio: Grid 1                                                *
 * Url: https://atcoder.jp/contests/dp/tasks/dp_h                   *
 * Lenguaje: c++                                                    *
 * Autor: Sebastian Vega                                            *
 * Fecha: 28-08-2020                                                *
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

const int H = 1000, W = 1000, MOD = 1e9 + 7;
int h, w;
ll dp[H][W];
char g[H][W];

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
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) cin >> g[i][j];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] == '#')
        dp[i][j] = 0;
      else if (!i && !j)
        dp[i][j] = 1;
      else if (!i)
        dp[i][j] = dp[i][j - 1];
      else if (!j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
    }
  }
  cout << dp[h - 1][w - 1] << endl;
  return 0;
}
/********************************************************************
 * Ejercicio: Knapsack 2                                            *
 * Url: https://atcoder.jp/contests/dp/tasks/dp_e                   *
 * Lenguaje: c++                                                    *
 * Autor: Sebastian Vega                                            *
 * Fecha: 02-09-2020                                                *
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

const int MAX_N = 101, MAX_W = 1e5 + 1;
const ll INF = 1e15;
ll N, W, w[MAX_N], v[MAX_N], dp[MAX_N][MAX_W];

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
  cin >> N >> W;
  for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
  for (int i = 0; i <= 100000; i++) {
    dp[0][i] = INF;
  }
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 100000; j++) {
      if (j >= v[i - 1])
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  for (int i = 100000; i >= 0; i--) {
    if (dp[N][i] <= W) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
/********************************************************************
 * Ejercicio: Knapsack 1                                            *
 * Url: https://atcoder.jp/contests/dp/tasks/dp_d                   *
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

const int N = 101, W = 1e5 + 1;
const ll INF = 1e18;
ll n, k, w[N], v[N], dp[N][W];

ll f(int i, int j) {
  if (j > k) return -INF;
  if (i == n) return 0;
  ll &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = max(f(i + 1, j + w[i]) + v[i], f(i + 1, j));
  return ans;
}

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
  for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
  memset(dp, -1, sizeof(dp));
  cout << f(0, 0) << endl;
  return 0;
}
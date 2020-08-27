/********************************************************************
 * Ejercicio: Frog 1                                                *
 * Url: https://atcoder.jp/contests/dp/tasks/dp_a                   *
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

const int N = 1e5 + 1;
int n, h[N], dp[N];

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
  cin >> n;
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) {
    if (i == 0)
      dp[i] = 0;
    else if (i == 1)
      dp[i] = abs(h[i] - h[i - 1]) + dp[i - 1];
    else
      dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1],
                  abs(h[i] - h[i - 2]) + dp[i - 2]);
  }
  cout << dp[n - 1] << endl;
  return 0;
}
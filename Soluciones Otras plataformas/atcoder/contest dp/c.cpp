/********************************************************************
 * Ejercicio: Vacation                                              *
 * Url: https://atcoder.jp/contests/dp/tasks/dp_c                   *
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
int n, a[N], b[N], c[N], dp[N][3];

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
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dp[i][0] = a[i];
      dp[i][1] = b[i];
      dp[i][2] = c[i];
    } else {
      dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);
    }
  }
  cout << *max_element(dp[n - 1], dp[n - 1] + 3) << endl;
  return 0;
}
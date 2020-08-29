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

const int MAX = 3 * 1e3 + 1;
int n, m, dp[MAX][MAX];
string s, t, ans;

int f(int i, int j) {
  if (i == n || j == m) return 0;
  int &r = dp[i][j];
  if (r != -1) return r;
  if (s[i] == t[j]) return r = f(i + 1, j + 1) + 1;
  return r = max(f(i, j + 1), f(i + 1, j));
}

void build(int i, int j) {
  if (i == n || j == m) return;
  if (s[i] == t[j]) {
    ans += s[i];
    build(i + 1, j + 1);
  } else if (f(i, j) == f(i, j + 1))
    build(i, j + 1);
  else
    build(i + 1, j);
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
  cin >> s >> t;
  n = SZ(s), m = SZ(t);
  memset(dp, -1, sizeof(dp));
  f(0, 0);
  ans = "";
  build(0, 0);
  cout << ans << endl;
  return 0;
}
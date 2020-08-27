#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define x first
#define y second

const int MAX = 16;
int n, target;
pii a[MAX];
double d[MAX][MAX];
double dp[1 << 16];

double f(int mask) {
  double &ans = dp[mask];
  if (ans > -1) return dp[mask];
  if (mask == target) return 0;
  int u;
  for (int i = 0; i < 2 * n; i++) {
    if (!(mask & (1 << i))) {
      u = i;
      break;
    }
  }
  ans = 1e9;
  for (int i = u + 1; i < 2 * n; i++) {
    if (!(mask & (1 << i))) {
      ans = min(ans, d[u][i] + f(mask | (1 << u) | (1 << i)));
    }
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  // freopen("out.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int cc = 1;
  string s;
  while (cin >> n, n != 0) {
    target = (1 << (2 * n)) - 1;
    for (int i = 0; i < 2 * n; i++) {
      cin >> s >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < 2 * n; i++) {
      for (int j = i + 1; j < 2 * n; j++) {
        d[i][j] = d[j][i] = hypot(a[i].x - a[j].x, a[i].y - a[j].y);
      }
    }
    fill(dp, dp + (1 << (n * 2)), -1);
    cout << fixed << setprecision(2);
    cout << "Case " << cc++ << ": " << f(0) << endl;
  }
  return 0;
}
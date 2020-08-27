#include <bits/stdc++.h>
using namespace std;

const int MAX = 1025;
int n, r, m[MAX][MAX];

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif
  int t, x, y, k, _x, _y;
  cin >> t;
  while (t--) {
    cin >> r >> n;
    memset(m, 0, sizeof(m));
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> k;
      _x = min(MAX - 1, x + r), _y = min(MAX - 1, y + r), x = max(0, x - r),
      y = max(0, y - r);
      for (int i = y; i <= _y; i++) {
        for (int j = x; j <= _x; j++) m[i][j] += k;
      }
    }
    k = -1;
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        if (m[j][i] > k) {
          k = m[j][i];
          y = j;
          x = i;
        }
      }
    }
    cout << x << ' ' << y << ' ' << k << endl;
  }
}
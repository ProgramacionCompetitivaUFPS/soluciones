#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string &s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, x = 0, y = 0; i < n; i++) {
    z[i] = max(0, min(z[i - x], y - i + 1));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      x = i, y = i + z[i], z[i]++;
    }
  }
  return z;
}

int main() {
#ifdef LOCAL
  freopen("z.txt", "r", stdin);
  // freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, n, ans;
  string s;
  vector<int> z;
  cin >> t;
  while (t--) {
    cin >> s;
    n = s.size();
    z = z_function(s);
    ans = n;
    for (int i = 1; i < n; i++) {
      if (n % i == 0 && z[i] + i == n) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
    if (t > 0) cout << endl;
  }
  return 0;
}
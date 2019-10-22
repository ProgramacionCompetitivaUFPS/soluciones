#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v.size()))

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  // freopen("out.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int c = 0;
  string s;
  while (getline(cin, s)) {
    for (int i = 0; i < sz(s); i++) {
      if (s[i] == '"' && c & 1)
        cout << "''", c--;
      else if (s[i] == '"')
        cout << "``", c++;
      else
        cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
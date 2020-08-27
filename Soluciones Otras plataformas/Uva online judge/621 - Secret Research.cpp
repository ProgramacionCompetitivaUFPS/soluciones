#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v.size()))

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    if (s == "1" || s == "4" || s == "78")
      cout << '+' << endl;
    else if (s[sz(s) - 1] == '5' && s[sz(s) - 2] == '3')
      cout << '-' << endl;
    else if (s[0] == '9' && s[sz(s) - 1] == '4')
      cout << '*' << endl;
    else
      cout << '?' << endl;
  }
}
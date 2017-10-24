/** 404A - Valera and X
  * http://codeforces.com/problemset/problem/404/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  string s[n];
  for(int i = 0; i < n; i++) cin >> s[i];
  char a = s[0][0];
  char b = s[0][1];
  if(a == b) cout << "NO\n";
  else {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if((i == j || n - 1 - i == j) && s[i][j] != a) {
          cout << "NO\n";
          return 0;
        } else if((i != j && n - 1 - i != j) && s[i][j] != b) {
          cout << "NO\n";
          return 0;
        }
      }
    }
    cout << "YES\n";
  }
  return 0;
}
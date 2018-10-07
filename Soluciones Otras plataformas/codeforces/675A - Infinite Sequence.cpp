/** 675A - Infinite Sequence
  * http://codeforces.com/problemset/problem/675/A
  * Category: Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  long long a, b, c;
  cin >> a >> b >> c;
  if((c == 0 && a != b) || (c > 0 && b < a) || (c < 0 && b > a)) cout << "NO\n";
  else if(c == 0) cout << "YES\n";
  else if(abs(b - a) % c == 0) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
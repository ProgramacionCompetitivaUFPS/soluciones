/** 624A - Save Luke
  * http://codeforces.com/problemset/problem/624/A
  * Category: Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  long double d, l, v1, v2;
  cin >> d >> l >> v1 >> v2;
  
  cout << setprecision(12) << (l - d)/(v1 + v2) << endl;
  return 0;
}
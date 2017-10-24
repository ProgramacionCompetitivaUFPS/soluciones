/** 606A - Magic Spheres
  * http://codeforces.com/problemset/problem/606/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int a[3], x[3], possible = 0;
  cin >> a[0] >> a[1] >> a[2] >> x[0] >> x[1] >> x[2];
  for(int i = 0; i < 3; i++) possible += max(0, (a[i] - x[i]) / 2) + min(0, a[i] - x[i]);
  if(possible >= 0) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
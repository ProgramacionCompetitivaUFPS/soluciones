/** 92A - Chips
  * http://codeforces.com/problemset/problem/92/A
  * Category: Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  int t = (n * (n + 1)) / 2;
  m %= t;
  double ans = -1.0 + sqrt(1.0 + (8.0 * m));
  ans /= 2.0;
  printf("%d\n", m - ((int)ans * ((int)ans + 1) / 2));
  return 0;
}
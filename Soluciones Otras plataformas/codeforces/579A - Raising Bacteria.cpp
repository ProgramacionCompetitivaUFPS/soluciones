/** 579A - Raising Bacteria
  * http://codeforces.com/problemset/problem/579/A
  * Category: Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, ans = 0;
  double lg;
  scanf("%d", &n);
  while(n > 0) {
    lg = log2(n);
    n -= pow(2, (int)lg);
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
/** 570B - Simple Game
  * http://codeforces.com/problemset/problem/570/B
  * Category: Implementation, Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int m, n;
  scanf("%d %d", &n, &m);
  if(n == 1) printf("1\n");
  else printf("%d\n", (m - 1 >= n - m && m - 1 > 0) ? m - 1 : m + 1);
  return 0;
}
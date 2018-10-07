/** 677A - Vanya and Fence
  * http://codeforces.com/problemset/problem/677/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, h, p, ans = 0;
  scanf("%d %d", &n, &h);
  while(n--) {
    scanf("%d", &p);
    ans += (p <= h) ? 1 : 2;  
  }
  printf("%d\n", ans);
  return 0;
}
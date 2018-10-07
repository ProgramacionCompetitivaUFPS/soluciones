/** 237A - Free Cash
  * http://codeforces.com/problemset/problem/237/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, h, m, ans = 0;
  scanf("%d", &n);
  map<int, int> cant;
  while(n--) {
    scanf("%d %d", &h, &m);
    cant[h * 60 + m]++;
    ans = max(cant[h * 60 + m], ans);
  }
  printf("%d\n", ans);
  return 0;
}
/** 702A - Maximum Increase
  * http://codeforces.com/problemset/problem/
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, tmp = 0, ans = 0, act, prev = 0;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &act);
    if(act > prev) tmp++;
    else tmp = 1;
    ans = max(ans, tmp);
    prev = act;
  }
  printf("%d\n", ans);
  return 0;
}
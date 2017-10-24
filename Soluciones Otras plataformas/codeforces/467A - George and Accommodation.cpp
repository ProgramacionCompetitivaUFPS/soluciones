/** 467A - George and Accommodation
  * http://codeforces.com/problemset/problem/467/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, p, q, ans = 0;
  scanf("%d", &n);
  while(n--) {
    scanf("%d %d", &p, &q);
    if(q - 2 >= p) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
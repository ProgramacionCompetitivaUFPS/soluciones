/** 479A - Expression
  * http://codeforces.com/problemset/problem/779/A
  * Category: Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int a, b, c, ans1, ans2;
  scanf("%d %d %d", &a, &b, &c);
  ans1 = max(a + b, a * b);
  ans1 = max(ans1 + c, ans1 * c);
  ans2 = max(b + c, b * c);
  ans2 = max(a + ans2, a * ans2);
  printf("%d\n", max(ans1, ans2));
  return 0;
}
/** 279B - Books
  * http://codeforces.com/problemset/problem/279/B
  * Category: 
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, t, sum = 0, parcialAns = 0, ans = 0;
  scanf("%d %d", &n, &t);
  int vals[n];
  for(int i = 0; i < n; i++) scanf("%d", &vals[i]);
  for(int j = 0, i = 0; j < n; j++) {
    sum += vals[j];
    if(sum <= t) {
      parcialAns = j - i + 1;
      ans = max(ans, parcialAns);
    } else {
      sum -= vals[i++];
      sum -= vals[j--];
    }
  }
  printf("%d\n", ans);
  return 0;
}
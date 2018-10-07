/** 810A - Straight «A»
  * http://codeforces.com/problemset/problem/810/A
  * Category: Implementation, Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, m, k, sum = 0, tmp;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    sum += tmp;
  }
  m = n;
  while(round((double)sum / m++) < k) sum += k;
  cout << m - n - 1 << endl;
  return 0;
}
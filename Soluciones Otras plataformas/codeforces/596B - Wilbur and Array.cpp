/** 596B - Wilbur and Array
  * http://codeforces.com/problemset/problem/596/B
  * Category: Greedy
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  long long n, prev = 0, act, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> act;
    ans += abs(act - prev);
    prev = act;
  }
  cout <<  ans << endl;
  return 0;
}
/** 461A - Appleman and Toastman
  * http://codeforces.com/problemset/problem/461/A
  * Category: Greedy, Sorting
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  int values[n];
  for(int i = 0; i < n; i++) cin >> values[i];
  sort(values, values + n);
  long long ans = (long long)values[n - 1] * n;
  for(int i = n; i - 2 >= 0; i--)  ans += ((long long)values[i - 2] * i);
  cout << ans << endl;
  return 0;
}
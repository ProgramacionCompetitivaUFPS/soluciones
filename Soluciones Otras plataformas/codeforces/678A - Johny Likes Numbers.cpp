/** 678A - Johny Likes Numbers
  * http://codeforces.com/problemset/problem/678/A
  * Category: Math
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, k;
  cin >> n >> k;
  cout << n + (k - (n % k)) << endl;
  return 0;
}
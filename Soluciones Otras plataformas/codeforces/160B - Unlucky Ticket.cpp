/** 160B - Unlucky Ticket
  * http://codeforces.com/problemset/problem/160/B
  * Category: Sorting, Greedy
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  vector<char> vals1, vals2;
  string s;
  bool flag1 = true, flag2 = true;
  cin >> n >> s;
  for(int i = 0; i < n; i++) vals1.push_back(s[i]);
  for(int i = n; i < 2 * n; i++) vals2.push_back(s[i]);
  sort(vals1.begin(), vals1.end());
  sort(vals2.begin(), vals2.end());
  for(int i = 0; i < n; i++) {
    if(vals1[i] <= vals2[i]) flag1 = false;
    if(vals1[i] >= vals2[i]) flag2 = false;
  }
  if(flag1 || flag2) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
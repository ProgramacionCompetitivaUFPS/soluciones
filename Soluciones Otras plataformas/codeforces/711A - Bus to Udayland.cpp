/** 711A - Bus to Udayland
  * http://codeforces.com/problemset/problem/711/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  string ans = "", tmp;
  bool flag = false;
  cin >> n;
  while(n--) {
    cin >> tmp;
    if(!flag) {
      if(tmp[0] == tmp[1] && tmp[1] == 'O') {
        ans += "++|" + tmp.substr(3, 2) + '\n';
        flag = true;
      } else if(tmp[3] == tmp[4] && tmp[4] == 'O') {
        ans += tmp.substr(0, 2) + "|++\n";
        flag = true;
      } else {
        ans += tmp + '\n';
      }
    } else {
      ans += tmp + '\n';
    }
  }
  if(flag) cout << "YES\n" << ans;
  else cout << "NO\n";
  return 0;
}
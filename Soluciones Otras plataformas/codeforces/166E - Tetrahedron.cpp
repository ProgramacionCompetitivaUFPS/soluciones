/** 166E - Tetrahedron
  * http://codeforces.com/problemset/problem/166/E
  * Category: 
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  long long mod = 1000000007;
  long long ans = 0;
  cin >> n;
  if(n == 1) cout << 0 << endl;
  else if(n == 2) cout << 3 << endl;
  else if(n == 3) cout << 6 << endl;
  else {
    long long ans = 1;
    for(int i = 0; i < n - 1; i++) {
      if(i == n - 2) ans = (((ans / 3 * 4) % mod) + ((ans / 3 * 3) % mod)) % mod ;
      else ans = (ans * 3) % mod;
    }
    cout << ans << endl;
  }

  return 0;
}
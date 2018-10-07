/** 474D - Flowers
  * http://codeforces.com/problemset/problem/474/D
  * Category: DP
  */

#include <bits/stdc++.h>
using namespace std;

long long memo[100010];
long long ans[100010];
long long mod = 1000000007;

void dp(int k) {
  memo[0] = 1;
  ans[0] = 0;
  int i = 1;
  for(; i < k; i++) {
    memo[i] = 1;
    ans[i] = i;
  }
  for(; i < 100010; i++) {
    memo[i] = (memo[i - 1] + memo[i - k]) % mod;
    ans[i] = (ans[i - 1]  + memo[i]) % mod;
  }
}

int main () {
  int t, k, a, b;
  cin >> t >> k;
  dp(k);
  while(t--) {
    cin >> a >> b;
    cout << (2 * mod + ans[b] - ans[a - 1]) % mod << '\n';
  }
  return 0;
}
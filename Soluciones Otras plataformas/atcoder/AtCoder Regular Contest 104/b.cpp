#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int n;
  string s;
  cin >> n >> s;
  int ans = 0, a, b;
  forn(i, 0, n) {
    a = b = 0;
    forn(j, i, n) {
      a += (s[j] == 'A');
      a -= (s[j] == 'T');
      b += (s[j] == 'C');
      b -= (s[j] == 'G');
      ans += (a == 0 && b == 0);
    }
  }
  cout << ans << endl;
  return 0;
}
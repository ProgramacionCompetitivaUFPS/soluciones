#include <bits/stdc++.h>
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x) 0
#endif
#define pb push_back
#define F first
#define S second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool is_palindrome(int n, int b) {
	deque<int> dq;
    while (n) {
        dq.push_front(n%b);
        n /= b;
    }
    for (int i = 0; i < SZ(dq)/2; i++) {
        if (dq[i] != dq[SZ(dq)-i-1]) return false;
    }
    return true;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
		if (n <= 2) { cout << n+1 << '\n'; continue; }
        int ans = n-1;
        bool yes = false;
        for (int b = 2; b*b <= n && !yes; b++) {
            yes = is_palindrome(n, b);
            if (yes) ans = b;
        }
		for (int x = 1; x*x < n && !yes; ++x) {
			if (n%x == 0 && n/x-1 > x) {
				ans = n/x-1;
			}
		}
        cout << ans << '\n';
    }
}

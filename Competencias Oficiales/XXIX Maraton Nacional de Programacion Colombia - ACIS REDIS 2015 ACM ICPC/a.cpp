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

void add(string &s) {
    bool carry = 1;
    for (int j = SZ(s)-1; j >= 0; j--) {
        if (carry) {
            if (s[j]+carry > '9') {
                s[j] = '0';
            } else {
                s[j] = s[j]+carry;
                carry = 0;
            }
        } else break;
    }
    if (carry) {
        s = '1'+s;
    }
}

void palindrome(string &s) {
    bool carry = 0;
    for (int i = 0, j = SZ(s)-1; j >= 0; j--, i++) {
        if (i < SZ(s)/2) {
            if (s[i] >= s[j]+carry) {
                s[j] = s[i];
                carry = 0;
            } else if (s[i] < s[j]+carry) {
                s[j] = s[i];
                carry = 1;
            }
        } else {
            if (carry) {
                if (s[j]+carry > '9') {
                    s[j] = s[SZ(s)-j-1] = '0';
                    carry = 1;
                } else {
                    s[j] = s[SZ(s)-j-1] = s[j]+carry;
                    carry = 0;
                }
            } else break;
        }
    }
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    while (cin >> n >> s) {
        while (n--) {
            add(s);
            palindrome(s);
            cout << s << '\n';
        }
    }
}

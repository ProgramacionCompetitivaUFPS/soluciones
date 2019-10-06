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


long long p[] = {257, 359};
long long mod[] = {1000000007, 1000000009};
long long X = 1000000010;

struct hashing {
	vector<long long> h[2], pot[2];
	int n;

	hashing(string s) {
		n = s.size();
		for (int i = 0; i < 2; ++i) {
			h[i].resize(n + 1);
			pot[i].resize(n + 1, 1);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 2; ++j) {
				h[j][i] = (h[j][i-1] * p[j] + s[i-1]) % mod[j];
				pot[j][i] = (pot[j][i-1] * p[j]) % mod[j];
			}
		}
	}
	//Hash del substring en el rango [i, j)
	long long hashValue(int i, int j) {
		long long a = (h[0][j] - (h[0][i] * pot[0][j-i] % mod[0]) + mod[0]) % mod[0];
		long long b = (h[1][j] - (h[1][i] * pot[1][j-i] % mod[1]) + mod[1]) % mod[1];
		return a*X + b;
	}
};

vector<string> split(string s, char c) {
    vector<string> v;
    istringstream iss(s);
    string sub;
    //while (iss >> sub) {
    while (getline(iss, sub, c)) {
        if(sub.size())v.push_back(sub);
    }
    return v;
}



int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s, t;

    while(cin >> n){
        getline(cin, s);
        getline(cin, s);
        hashing h1 = hashing(s);
        for (int i = 0; i < n; i++) {
            cin >> t;
            vector<string> vt = split(t, '*');
            int tot = 0, sz = 0, ind = 0;
            for(int j = 0; j < vt.size(); j++){
                hashing h2 = hashing(vt[j]);
                sz = vt[j].size();
                ll word = h2.hashValue(0, sz);
                if(ind >= s.size())break;
                while(ind+sz <= s.size()){
                    if(h1.hashValue(ind, ind+sz) != word)ind++;
                    else{
                        ind += sz;
                        tot++;
                        break;
                    }
                }
            }
            if(tot == vt.size())cout << "yes\n";
            else cout << "no\n";
        }

    }


}

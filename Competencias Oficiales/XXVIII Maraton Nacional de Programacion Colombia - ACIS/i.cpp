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

const int tam = 1005;
int dy[] = {1,0,-1, 0};
int dx[] = {0,1, 0,-1};
char grid[tam][tam];
int Y, X;

bool floodfill(int y, int x, char c1, char c2) {
    if (y < 0 || y >= Y || x < 0 || x >= X) return 0;
    if (grid[y][x] != c1) return 0;
    if (y == Y-1) return 1;
    grid[y][x] = c2;
    bool yes = false;
    for (int i = 0; i < 4 && !yes; i++) {
        yes = floodfill(y + dy[i], x + dx[i], c1, c2);
    }
    return yes;
}

vector<deque<int>> col;

bool valide(int _y, int _x) {
    for (int i = 0, y, x; i < 4; i++) {
        y = _y+dy[i];
        x = _x+dx[i];
        if (y < 0 || y >= Y || x < 0 || x >= X) continue;
        if (grid[y][x] == '*') return true;
    }
    return false;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int S, s, y, x;
    while (cin >> Y >> X >> S) {
        col.assign(X, {});
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '#') {
                    col[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < X; j++) {
            if (!ans && floodfill(0, j, '.', '*')) {
                ans = 1;
            }
        }
        if (ans) {
            cout << "0\n";
            while (S--) cin >> s;
        } else {
            for (int i = 1; i <= S; i++) {
                cin >> s;
                if (s > 0) {
                    x = s-1;
                    if (SZ(col[x])) {
                        y = col[x].front();
                        col[x].pop_front();
                        grid[y][x] = '.';
                        if (!ans && floodfill(y, x, '.', '*')) {
                            ans = i;
                        }
                    }
                } else {
                    x = (-s)-1;
                    if (SZ(col[x])) {
                        y = col[x].back();
                        col[x].pop_back();
                        grid[y][x] = '.';
                        if (y == 0 || valide(y, x)) {
                            if (!ans && floodfill(y, x, '.', '*')) {
                                ans = -i;
                            }
                        }
                    }
                }
            }
            if (ans) cout << ans << '\n';
            else cout << "X\n";
        }
    }
}

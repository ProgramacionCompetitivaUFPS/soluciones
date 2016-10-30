/********************************************************************
 * Ejercicio:  F - Fire                                             *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 22-10-2016                                                *
 *******************************************************************/

 #include <bits/stdc++.h>
using namespace std;

map<int, set<pair<int,int> > > tx;
int r, c, xi, yi;
string maze[1005];
set<pair<int, int> > vis;

void aum(int t) {
	int x[] = {0, 1, 0, -1};
	int y[] = {1, 0, -1, 0};
	int i, j, _x, _y;
	for(set<pair<int, int> >::iterator it = tx[t - 1].begin(); it != tx[t - 1].end(); ++it) {
		tx[t].insert(*it);
	}
	
	for(set<pair<int, int> >::iterator it = tx[t - 1].begin(); it != tx[t - 1].end(); ++it) {
		for(j = 0; j < 4; j++) {
			_x = it->first + x[j];
			_y = it->second + y[j];
			if(_x >= 0 && _x < r && _y >= 0 && _y < c && maze[_x][_y] == '.') {
				tx[t].insert(make_pair(_x, _y));
			}
		}
	}
}
bool seQuema(int x, int y, int t) {
	for(set<pair<int, int> >::iterator it = tx[t].begin(); it != tx[t].end(); ++it) {
		if(it->first == x && it->second == y) {
			return true;
		}
	}
	return false;
}

int bfs(int x, int y) {
	int _x[] = {0, 1, 0, -1};
	int i;
	int _y[] = {1, 0, -1, 0};
	int ax, ay;
	queue<int> px;
	queue<int> py;
	queue<int> pt;
	px.push(x);
	py.push(y);
	pt.push(0);
	vis.clear();
	vis.insert(make_pair(x,y));
	int a, b, t;
	while(!px.empty()) {
		a = px.front();
		b = py.front();
		t = pt.front();
		px.pop(); py.pop(); pt.pop();
		if(tx.count(t + 1) == 0) {
			aum(t + 1);
		}
		for(i = 0; i < 4; i++) {
			ax = a + _x[i];
			ay = b + _y[i];
			if(ax >= 0 && ax < r && ay >= 0 && ay < c && maze[ax][ay] == '.' && vis.count(make_pair(ax, ay)) == 0 && !seQuema(ax, ay, t + 1)) {
				if(min(ax, ay) == 0 || ax == r - 1 || ay == c - 1) {
					return t + 1;
				}
				vis.insert(make_pair(ax, ay));
				px.push(ax);
				py.push(ay);
				pt.push(t + 1);
			}
		}
	}
	return -1;
}



int main() {
	ios_base::sync_with_stdio (false);cin.tie(NULL);
	int n, i, j, rta;
	cin >> n;
	while(n-- > 0) {
		tx.clear();
		cin >> r >> c;
		for(i = 0; i < r; i++) {
			cin >> maze[i];
			for(j = 0; j < c; j++) {
				if(maze[i][j] == 'F') {
					tx[0].insert(make_pair(i,j));
				}
				if(maze[i][j] == 'J') {
					xi = i;
					yi = j;
				}
			}
		}
		if(min(xi, yi) == 0 || xi == r - 1 || yi == c - 1) {
			cout << "1\n";
		} else {
			rta = bfs(xi, yi);
			if(rta != -1) {
				cout << rta + 1 << "\n";
			} else {
				cout << "IMPOSSIBLE\n";
			}
		}
		
		
	}
	return 0;
}
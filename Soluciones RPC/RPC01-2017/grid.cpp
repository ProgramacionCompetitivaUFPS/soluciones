/************************************************************************
 * Ejercicio:  G Grid				                         			*
 * Lenguaje: c++                                                    	*
 * Autor: Make Chocoramo Great Again (Melissa Delgado - Gerson Lázaro	*
 * Fecha: 11-02-2017                                            	    *
 ***********************************************************************/

 #include <bits/stdc++.h>

using namespace std;

int m, n;
vector<string> square;
int dx [] = {1, -1, 0, 0};
int dy [] = {0, 0, 1, -1};

int bfs(){
	int xx, yy, s, cont, x, y, i;
	
	queue< pair<int, pair<int,int> > > q;
	
	q.push( make_pair(0, make_pair(0, 0) ) );
	
	while( !q.empty() ){
		cont =  q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();
		
		if( x == m-1 && y == n-1 ){
			return cont;
		}
		
		if( square[x][y] != '-' ){
			s = square[x][y] - (int)'0';
			square[x][y] = '-';		
			
			for( i = 0; i < 4; i++){
				xx = x + s*dx[i];
				yy = y + s*dy[i];
				
				if( xx >= 0 && xx < m && yy >= 0 && yy < n && square[xx][yy] != '-' ){
					q.push( make_pair( cont+1, make_pair(xx, yy) ) );
				}
			}
		}
	}
	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int i;
	string s;
	cin >> m >> n;
	square.clear();
	
	for( i = 0; i < m; i++){
		cin >> s;
		square.push_back( s );
	}
	
	i = bfs();
	if( i == -1 ){
		cout << "IMPOSSIBLE\n";
	} else{
		cout << i << "\n";
	}
	
	return 0;
}
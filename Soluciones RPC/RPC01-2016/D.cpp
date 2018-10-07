/********************************************************************
 * Ejercicio: D Ga 			                               			*
 * Url: https://acm.javeriana.edu.co/maratones/2016/01/            	*
 * Lenguaje: c++	                                                *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -   	*
 * Gerson Lázaro                                                    *
 * Fecha: 13-02-2016                                              	*
 *******************************************************************/

 #include <bits/stdc++.h>

using namespace std;

char board[105][105];
int n, rta;
int dx[]={1, 1, 1, 0, -1, -1, -1, 0};
int dy[]={-1, 0, 1, 1, 1, 0, -1, -1};

void init(){
	int i;
	rta=0;
	for(i=0; i<=n; i++){
		memset(board[i], '-', sizeof(board[i]));	
	}
}

void floodfill(int y, int x){
	if(board[y][x]=='b' || board[y][x]=='x'){
		return;
	}
	
	if(board[y][x]=='-'){
		rta++;
	}
	
	board[y][x]='x';
	
	int i, xx, yy;
	for(i=0; i<8; i++){
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=0 && xx<n && yy>=0 && yy<n){
			floodfill(yy,xx);
		}
	}
	
}

int main() {
	int tc, i, j, r;
	set<pair<int, int> > coords;
	char x;
	
	
	scanf("%d", &tc);
	
	while(tc){
		scanf("%d", &n);
		init();
		coords.clear();
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				cin>>board[i][j];
				
				if(board[i][j]=='w'){
					coords.insert(make_pair(i, j));
				}
			}
		}
		
		r=-1;
		
		set<pair<int, int> >::iterator it;
		for(it=coords.begin(); it!=coords.end(); it++){
			if(board[it->first][it->second]=='w'){
				floodfill(it->first, it->second);
				if(rta>r)	r=rta;
			}
		}
		
		cout<<r<<"\n";
		
		tc--;
	}
	
	return 0;
}
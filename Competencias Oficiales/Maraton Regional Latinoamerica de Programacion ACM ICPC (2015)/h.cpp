#include <bits/stdc++.h>

using namespace std;

int r, c;
long long rta;
int cube[105][105];
int vis[105][105];
int dy[]={-1, 1, 0, 0};
int dx[]={0, 0, -1, 1};

void init(){
	memset(vis, -1, sizeof(vis));
	memset(cube, 0, sizeof(cube));
}

void dfs(int y, int x){
	int yy, xx, i;
	vis[y][x]=1;

	for(i=0; i<4; i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=0 && xx<c && yy>=0 && yy<r && vis[yy][xx]==-1 && cube[yy][xx]==cube[y][x]){
			dfs(yy, xx);
		}
	}
}

void countY(){
	int j, jj, i, dir, aux;
	//dir 0->iguales  1-> este  -1 -> oeste
	j=0; jj=1;

	while(jj<c){
		dir=cube[0][j]-cube[0][jj];

		if(dir!=0){
			rta++;
			dir=dir>0?1:-1;
		}

		for(i=1; i<r; i++){
			aux=cube[i][j]-cube[i][jj];

			if(aux!=0){
				aux=aux>0?1:-1;

				if(dir!=aux){
					rta++;
				}else{
					if(aux==1 && (cube[i-1][jj]>=cube[i][j] || cube[i][jj]>=cube[i-1][j]) ){
						rta++;
					}else if(aux==-1 && (cube[i-1][jj]<=cube[i][j] || cube[i][jj]<=cube[i-1][j]) ){
						rta++;
					}
				}
			}
			dir=aux;
		}

		j=jj;
		jj++;
	}
}

void countX(){
	int i, ii, j, dir, aux;
	//dir 0->iguales  1-> sur  -1-> norte
	i=0; ii=1;

	while(ii<r){
		
		dir=cube[i][0]-cube[ii][0];

		if(dir!=0){
			rta++;
			dir=dir>0?1:-1;
		}

		for(j=1; j<c; j++){
			aux=cube[i][j]-cube[ii][j];

			if(aux!=0){
				aux=aux>0?1:-1;

				if(dir!=aux){
					rta++;
				}else{
					if(aux==1 && (cube[i][j-1]<=cube[ii][j] || cube[i][j]<=cube[ii][j-1]) ){
						rta++;
					}else if(aux==-1 && (cube[i][j-1]>=cube[ii][j] || cube[i][j]>=cube[ii][j-1]) ){
						rta++;
					}
				}
			}
			dir=aux;
		}

		i=ii;
		ii++;
	}

}

int main(){
	ios_base::sync_with_stdio(false);

	int i,j;

	while(cin>>r){
		cin>>c;

		init();

		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				cin>>cube[i][j];
			}
		}

		rta=5;

		//Caras Superiores
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				if(vis[i][j]==-1){
					rta++;
					dfs(i, j);
				}
			}
		}

		//Caras ejeX
		countX();
		countY();
		
		cout<<rta<<"\n";
	}
	return 0;
}
/********************************************************************
 * Ejercicio: Karel the Robot		                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/06              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro )                                                  *
 *******************************************************************/

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

char pos[102][102];
int path[102][102][4][10];
int a, b, cantIns, alcanzados;
char ins[10];

void init(){
	alcanzados=0;
	int i,j, k;
	for(i=1; i<=a; i++){
		for(j=1; j<=b; j++){
			for(k=0; k<10; k++){
				path[i][j][0][k]=0;
				path[i][j][1][k]=0;
				path[i][j][2][k]=0;
				path[i][j][3][k]=0;
			}
		}
	}
}

bool dfs(int x, int y, int dir, int insActual){
	if(pos[x][y]=='E' || path[x][y][dir][insActual]==1){
		return true;
	}
	if(path[x][y][dir][insActual]==2){
		return false;
	}
	if(path[x][y][dir][insActual]==4){
		path[x][y][dir][insActual]=2;
		return false;
	}

	path[x][y][dir][insActual]=4;
	int xx, yy, dir2, ins2;
	xx=x;
	yy=y;
	dir2=dir;
	if(ins[insActual]=='S'){
		if(dir==0){
			xx--;
			if(xx<=0) xx++;
		}else if(dir==1){
			yy++;
			if(yy>b) yy--;
		}else if(dir==2){
			xx++;
			if(xx>a) xx--;
		}else{
			yy--;
			if(yy<=0) yy++;
		}
		
		if(pos[xx][yy]=='X'){
			xx=x;
			yy=y;
		}
	}else if(ins[insActual]=='L'){
		dir2--;
		if(dir2<0)	dir2=3;
	}else{
		dir2++;
		dir2=dir2%4;
	}
	ins2=insActual+1;
	ins2=ins2%cantIns;

	if(dfs(xx,yy,dir2,ins2)){
		path[x][y][dir][insActual]=1;
		return true;
	}else{
		path[x][y][dir][insActual]=2;
		return false;
	}
}

int main(){
	int i, j, cantS, cantX;
	while(scanf("%i %i", &a, &b)==2){
		char aux[b];
		cantX=0;
		init();
		for(i=1; i<=a; i++){
			scanf("%s",aux);
			for(j=0; j<b; j++){
				pos[i][j+1]=aux[j];
				if(aux[j]=='X'){
					cantX++;
				}else if(aux[j]=='E'){
					path[i][j+1][0][0]=1;
				}
			}
		}

		scanf("%i", &cantIns);
		cantS=0;
		scanf("%s", ins);
		for(i=0; i<cantIns; i++){
			if(ins[i]=='S') cantS++;
		}

		if(cantS==0){
			alcanzados=1;
		}else{
			for(i=1; i<=a; i++){
				for(j=1; j<=b; j++){
					if(path[i][j][0][0]==0 && pos[i][j]!='X'){
						dfs(i,j,0,0);
					}
				}
			}
			
			for(i=1; i<=a; i++){
				for(j=1; j<=b; j++){
					if(path[i][j][0][0]==1) alcanzados++;
				}
			}
		}


		if((alcanzados+cantX)==(a*b)){
			printf("OK\n");
		}else{
			printf("%i\n", alcanzados);
		}
	}
	return 0;
}
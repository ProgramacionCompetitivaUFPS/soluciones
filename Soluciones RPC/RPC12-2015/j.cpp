/********************************************************************
 * Ejercicio: Jury Jeopardy 	                                    *
 * Url: https://acm.javeriana.edu.co/maratones/2015/12              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 24-10-2015                                                *
 *******************************************************************/

#include <iostream>
#include <map>

/*
Ob la di ob la da life goes naaaah
la la how the life goes on? :3
*/
using namespace std;

map<pair<int,int>, int> coordenadas;
map<char,int> change;
pair<int, int> direcciones[4][4]; //pair<dxy, dir>
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int pos[2]={0,0};
int minX, minY, maxX, maxY, dir, x, y;

void init(){
	direcciones[0][0]=make_pair(0,0);
	direcciones[0][1]=make_pair(3,2);
	direcciones[0][2]=make_pair(2,3);
	direcciones[0][3]=make_pair(1,1);
	
	direcciones[1][0]=make_pair(1,1);
	direcciones[1][1]=make_pair(2,3);
	direcciones[1][2]=make_pair(3,2);
	direcciones[1][3]=make_pair(0,0);
	
	direcciones[2][0]=make_pair(3,2);
	direcciones[2][1]=make_pair(1,1);
	direcciones[2][2]=make_pair(0,0);
	direcciones[2][3]=make_pair(2,3);
	
	direcciones[3][0]=make_pair(2,3);
	direcciones[3][1]=make_pair(0,0);
	direcciones[3][2]=make_pair(1,1);
	direcciones[3][3]=make_pair(3,2);
	
	change['F']=0;
	change['R']=1;
	change['L']=2;
	change['B']=3;
}

void makeMove(int move){
	int desp=direcciones[dir][move].first;
	dir=direcciones[dir][move].second;
	
	x+=dx[desp];
	y+=dy[desp];
	
	if(x>maxX){
		maxX=x;
	}
	if(y>maxY){
		maxY=y;
	}
	if(y<minY){
		minY=y;
	}
	
	coordenadas[make_pair(x,y)]++;
}

int main() {
	int casos, i, j, h, w;
	string mov;
	init();
	cin>>casos;
	cout<<casos<<"\n";
	while(casos>0){
		cin>>mov;
		coordenadas.clear();
		minX=minY=maxX=maxY=0;
		dir=0;
		x=y=0;
		coordenadas[make_pair(x,y)]++;
		
		for(i=0; i<mov.size(); i++){
			makeMove(change[mov[i]]);
		}
		
		h=(minY*-1)+maxY+3;
		w=maxX+2;
		
		cout<<h<<" "<<w<<"\n";
		maxY++;
		for(i=0; i<h; i++){
			y=maxY;
			maxY--;
			for(j=0; j<w; j++){
				if(coordenadas[make_pair(j,y)]==0){
					cout<<"#";
				}else{
					cout<<".";
				}
			}
			cout<<"\n";
		}
		casos--;
	}
	return 0;
}
/********************************************************************
 * Ejercicio:  L - Tiles                                            *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 10-09-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int h, l;
int table[210][210];
int area;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int floodfill(int i, int j, int color){
	int xx, yy, k;
	
	int acum = 1;
	table[i][j] = -1;
	
	for(k = 0; k < 4; k++){
		xx = i + dx[k];
		yy = j + dy[k];
		
		if( xx >= 0 && xx < l && yy >=0 && yy < h && table[xx][yy] == color ){
			acum += floodfill(xx, yy, color);
		}
	}
	
	return acum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int i, j;
	
	while( cin >> l){
		cin >> h;
	
		memset(table, -1, sizeof(table[0][0])*210*210 );
		
		for(i = 0; i < l; i++){
			for(j = 0; j < h; j++){
				cin >> table[i][j];
			}	
		}
		
		int a;
		area = LONG_MAX;	
		for(i = 0; i < l; i++){
			for(j = 0; j < h; j++){
				if( table[i][j] != -1 ){
					a = floodfill(i, j, table[i][j] ); 		
					area = min(area, a );
				}
			}	
		}
		
		cout<<area<<"\n";
		
	}
	
	return 0;
}
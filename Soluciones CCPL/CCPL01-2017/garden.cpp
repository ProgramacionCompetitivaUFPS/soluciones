/********************************************************************
 * Ejercicio: G -  Garden of Eden	    	                        *
 * Lenguaje: c++                                          			*
 * Autor: Melissa Delgado								            *
 * Fecha: 18-02-2017                                                *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

int table[2][2][2];
int state[50];
int n;
int ady[55][4][2]; // POSICIÓN

void init(){
	int i, j;
	for(i = 0; i < n; i++ ){
		for(j = 0; j < 4; j++){
			ady[i][j][0] = -1;
			ady[i][j][1] = -1;
		}
	}
}

void build_table(int id){
	int i, j, k;
	
	/* Tabla {i,j,k} = value
	{0,0,0} = 0 */
	for( i = 0; i < 2; i++ ) {
        for ( j = 0; j < 2; j++ ) {
            for ( k = 0; k < 2; k++ ) {
                table[i][j][k] = id & 1;
                id >>= 1;
            }
        }
    }
}

void build_graph(){
	int i, cur, next, next2, id, s1, s2;
	
	for( i = 0; i < n; i++ ){
		for( cur = 0; cur < 2; cur++ ){
			for( next = 0; next < 2; next++ ){
				for( next2 = 0; next2 < 2; next2++ ){
					id = (i + 1) %n;
					if( table[cur][next][next2] == state[id] ){
						s1 = ( cur * 2 ) + ( next * 1 );
						s2 = ( next * 2 ) + ( next2 * 1 );
			
						ady[i][s1][next2] = s2;
					}
				}
			}
		} 
	}
}

bool dfs(int src, int state, int initial, int initialState){
	int j, dest, nextState;
	
	if( src == initial && state == initialState ){
		return true;
	}
	
	dest = (src + 1) % n;
	
	for( j = 0; j < 2; j++ ){
		nextState = ady[src][state][j];
		
		if( nextState != -1 ){
			if( src == n-1 ){
				if( dest == initial && nextState == initialState ){
					 return true;	
				}
			}else if( dfs(dest, nextState, initial, initialState) ) return true;	
		}	
	}

	return false;
}

bool resolve(){
	int i, j, dest, state;
	
	for( i = 0; i < 4; i++){
		for( j = 0; j < 2; j++ ){
			state = ady[0][i][j];
			
			if( state != -1 ){
				if( dfs(1, state, 0, i) ) return true;
			}	
		}
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int id, i;
	string s;
	
	while( cin >> id ){
		cin >> n >> s;
		
		init();
		for( i = 0; i < n; i++ ){
			state[i] = s[i] - '0';
		}
		build_table(id);
		build_graph();
		
		
		if( resolve() ){
			cout << "REACHABLE\n";
		}else{
			cout << "GARDEN OF EDEN\n";
		}
	}
	return 0;
}
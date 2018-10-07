/********************************************************************
 * Ejercicio:  H - Tree Recovery                                    *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 22-10-2016                                                *
 *******************************************************************/

 #include <bits/stdc++.h>

using namespace std;

int ady[27][2];
bool table[27][27];
int v, r;
string pos;
map<char, int> nodes;
map<int, char> letters;

void init(){
	int i;
	for(i = 0; i <= v; i++){
		ady[i][0] = -1;
		ady[i][1] = -1;
		memset(table[i], 0, sizeof(table[i]) );
	}
}

void buildTree(int root, int level, int src, int end, int child){
	//cout<<root<<" "<<level<<" "<<src<<" "<<end<<" "<<child<<endl;
	int i, j;
	
	for(i = level; i < v; i++){ //Niveles
		for(j = src; j < end; j++){
			if( table[i][j] ){
				if(root == -1){
					r = i;
				}else{
					ady[root][child] = i;
				}
				buildTree(i, i+1, src, j, 0);
				buildTree(i, i+1, j+1, end, 1);
				return;
			}
		}
	}
}

void postorder(int root){
	//cout << root <<endl;
	if( ady[root][0] != -1 ){
		postorder( ady[root][0] );
	}
	
	if( ady[root][1] != -1 ){
		postorder( ady[root][1] );
	}
	
	cout << letters[root];
} 

int main(){
	string pre, in;
	int i;
	
	
	while( cin >> pre ){
		v = pre.size();
		init();
		nodes.clear();
		letters.clear();
		cin >> in;
		
		for( i = 0; i < v; i++ ){
			nodes[ pre[i] ] = i;
			letters[i] = pre[i];
		}
		
		for( i = 0; i < v; i++ ){
			table[ nodes[ in[i] ] ][i] = true;
		}
		
		buildTree( -1, 0, 0, v, 0 );
		
		/*for( i = 0; i < v; i++){
			cout << i << " izq: " << ady[i][0] << "   der: "<<ady[i][1]<<endl; 
		}*/
		pos = "";
		postorder(r);
		
		cout << "\n"; 
	}
	
	return 0;
}
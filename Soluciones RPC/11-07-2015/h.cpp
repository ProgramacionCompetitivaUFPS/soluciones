/********************************************************************
 * Ejercicio: Self Intersecting Path                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/06              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro )                                                  *
 *******************************************************************/

#include <cstdio>
#include <deque>
#define Point pair<long long int,long long int> //x,y

using namespace std;

deque< pair<Point,Point> > coordenadas;
long long int  dx[4]={0,1,0,-1};
long long int dy[4]={1,0,-1,0};
long long int dir, cont;
long long int x, y;
bool flag;
Point w, src, dest;

void init(){
	coordenadas.clear();

	w=Point(0,0);
	//coordenadas.push_back(make_pair(w,w));
	dir=0;
	x=y=0;
	cont=0;
	flag=true;
}

void validar(){
	if(dir==0){
		if((y>=src.second && x>=dest.first && x<= src.first && w.second<=src.second) || (y>=src.second && x>=src.first && x<=dest.first && w.second<=src.second)){
			flag=false;
		}
	}else if(dir==1){
		if((x>=src.first && y>=src.second && y<=dest.second && w.first<=src.first) || (x>=src.first && y>=dest.second && y<=src.second && w.first<=src.first)){
			flag=false;
		}

	}else if(dir==2){
		if((y<=src.second && x>=src.first && x<=dest.first && w.second>=src.second) || (y<=src.second && x>=dest.first && x<=src.first && w.second>=src.second)){
			flag=false;
		}

	}else if(dir==3){
		if((x<=src.first && y<=src.second && y>=dest.second && w.first>=src.first) || (x<=src.first && y>=src.second && y<=dest.second && w.first>=src.first)){
			flag=false;
		}
	}
}

int main(){
	long long int n, j;
	long long int aux;

	while(scanf("%lli", &n)==1){
		init();
		j=0;
		while(j<n){
			scanf("%lli", &aux);
			x+=dx[dir]*aux;
			y+=dy[dir]*aux;

			if(flag){
                for(int k=2;k<=coordenadas.size();k++)
                {
                    src=coordenadas.at(coordenadas.size()-k).first;
                    dest=coordenadas.at(coordenadas.size()-k).second;
                    validar();
                    if(coordenadas.size()>13){
                        coordenadas.pop_front();
                    }
                }
            }
			if(flag)  cont++;
			coordenadas.push_back(make_pair(w, Point(x,y)));
			w=Point(x,y);
			dir=(dir+1)%4;
			j++;
		}
		if(cont==n){
			printf("OK\n");
		}else{
			printf("%lli\n", cont);
		}
	}
	return 0;
}

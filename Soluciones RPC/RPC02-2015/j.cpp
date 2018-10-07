/********************************************************************
 * Ejercicio: Units					                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/02              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 14-03-2015                                                *
 *******************************************************************/

#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <math.h>
#define endl "\n"
using namespace std;

int n, i, j;
long double proporcion[10][10];
string nombre[10];
map<long double, int>mapa;

int buscar(string x){
	for(int y=0; y<n; y++){
		if(x.compare(nombre[y])==0){
			return y;
		}
	}
	return 0;
}

void completarGrafo(){
	int k=0;
	while(k<n){
		for(i=0; i<n; i++){
			if(i!=k){
				for(j=0; j<n; j++){
					if(j!=i && j!=k){
						if(proporcion[i][j]==-1 && proporcion[i][k]!=-1 && proporcion[k][j]!=-1){
							proporcion[i][j]=proporcion[i][k]*proporcion[k][j];
							proporcion[j][i]=1/proporcion[i][j];
						}
					}
				}
			}
		}
		k++;
	}
	
	for(i=0; i<n; i++){
		mapa[proporcion[0][i]]=i;
	}
}

int main() {
	cin>>n;
	int k;
	while(n!=0){
		mapa.clear();
		for(i=0; i<n; i++){
			cin>>nombre[i];
		}
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i==j){
					proporcion[i][j]=1;
				}else{
					proporcion[i][j]=-1;
				}
			}
		}
		
		string aux;
		long double valor;
		for(i=1; i<n; i++){
			cin>>aux;
			j=buscar(aux);
			cin>>aux;
			cin>>valor;
			cin>>aux;
			k=buscar(aux);
			proporcion[j][k]=valor;
			proporcion[k][j]=(1/valor);
		}
		
		completarGrafo();
		
		map<long double, int>::iterator it;
		it=mapa.begin();
		int mayor=it->second;
		cout<<"1"<<nombre[mayor];
		it++;
		while(it!=mapa.end()){
			cout<<" = ";
			long double aux=proporcion[mayor][it->second];
			printf("%.0Lf", aux);
			cout<<nombre[it->second];
			it++;
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}
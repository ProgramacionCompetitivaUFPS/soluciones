/********************************************************************
 * Ejercicio:  B -  Falcon Dive                                     *
 * Lenguaje: c++                                                    *
 * Autor: Elizabeth Ramirez                                         *
 * Fecha: 08-08-2016                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	char c,trash;
	int m,n;
	cin>>m>>n>>trash>>c>>trash;
	while(m!=0){
		bool veri=false;
		char mat1[m][n],mat2[m][n];
		vector <pair<int,int> >ve;
		pair<int,int> coor;
		int x,y;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>trash;
				mat1[i][j]=trash;
				if(!veri&&trash==c){
					coor=make_pair(i,j);
					veri=true;
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>trash;
				if(trash==c){
					ve.push_back(make_pair(i,j));
				}
				if(trash!=c){
					mat1[i][j]=trash;
				}
			}
		}
		
		x=coor.first-ve[0].first;
		y=coor.second-ve[0].second;
		for(int i=0;i<ve.size();i++){
			int ii,jj;
			ii=ve[i].first-x;
			jj=ve[i].second-y;
			if(ii<m&&ii>=0&&jj<n&&jj>=0)mat1[ii][jj]=c;
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<mat1[i][j];
			}cout<<"\n";
		}cout<<"\n";
		
		cin>>m>>n>>trash>>c>>trash;
	}
	return 0;
}

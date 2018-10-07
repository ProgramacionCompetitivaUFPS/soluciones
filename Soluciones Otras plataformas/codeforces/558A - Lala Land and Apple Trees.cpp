/********************************************************************
 * Ejercicio: Lala Land and Apple Trees                             *
 * Url: http://codeforces.com/problemset/problem/558/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/



#include <cstdio>
#include <map>
using namespace std;

int main() {
	int n,neg=0,pos=0, aux1,aux2,lim;
	map<int, int> may, men;
	scanf("%i",&n);
	while(n>0){
		scanf("%i %i", &aux1, &aux2);
		if(aux1<0){
			aux1*=-1;
			neg++;
			men[aux1]=aux2;
		}else{
			pos++;
			may[aux1]=aux2;
		}
		n--;
	}
	int rta=0,i;
	if(pos>neg){
		for (map<int,int>::iterator it=men.begin(); it!=men.end(); ++it){
			rta+=it->second;
		}
		i=0;
		for (map<int,int>::iterator it=may.begin(); i<neg+1; ++it,i++){
			rta+=it->second;
		}
	}else if(pos==neg){
		for (map<int,int>::iterator it=men.begin(); it!=men.end(); ++it){
			rta+=it->second;
		}
		for (map<int,int>::iterator it=may.begin(); it!=may.end(); ++it){
			rta+=it->second;
		}
	}else{
		for (map<int,int>::iterator it=may.begin(); it!=may.end(); ++it){
			rta+=it->second;
		}
		i=0;
		for (map<int,int>::iterator it=men.begin(); i<pos+1; ++it,i++){
			rta+=it->second;
		}
	}
	printf("%i\n", rta);
	return 0;
}
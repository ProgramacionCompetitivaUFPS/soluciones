/********************************************************************
 * Ejercicio: Train Passengers		                                *
 * Url: https://acm.javeriana.edu.co/maratones/2015/06              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro )                                                  *
 *******************************************************************/
#include <iostream>

using namespace std;

int main() {
	long long c;
	int e, i;
	bool flag=true;
	long long in, out, esp, tren;
	cin>>c>>e;
	i=2;
	tren=0;
	cin>>out>>in>>esp;
	tren+=in;
	if(out!=0 || in>c || (esp>0 && tren<c)){
		flag=false;
	}
	while(i<=e){
		cin>>out>>in>>esp;
		tren-=out;
		tren+=in;
		if(tren>c || tren<0 || (i==e && esp!=0) || (esp>0 && tren<c)){
			flag=false;
		}
		
		i++;
	}
	
	if(tren!=0){
		flag=false;
	}
	
	if(flag){
		cout<<"possible\n";
	}else{
		cout<<"impossible\n";
	}
	
	
	return 0;
}
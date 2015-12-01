/********************************************************************
 * Ejercicio: Gerald's Hexagon                                      *
 * Url: http://codeforces.com/problemset/problem/560/C              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/


#include <cstdio>
using namespace std;

int main() {
	int a1,a2,a3,a4,a5,a6,control,lim1,lim2;
	bool flag1=false, flag2=false;
	scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6);
	control=a1+a2;
	lim1=a2;
	lim2=a4;
	int rta=0;
	while(control>0){
		if(!flag1 && !flag2){
			rta+=((a3*2)+1);
			a3++;
		}else if((flag1 && !flag2) || (!flag1 && flag2)){
			rta+=(a3*2);
		}else if(flag1 && flag2){
			rta+=((a3*2)-1);
			a3--;
		}
		lim1--;
		if(lim1==0){
			lim1=a1;
			flag1=true;
		}
		lim2--;
		if(lim2==0){
			lim2=a5;
			flag2=true;
		}
		control--;
	}
	printf("%d", rta);
	return 0;
}
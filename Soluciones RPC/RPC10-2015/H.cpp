/********************************************************************
 * Ejercicio: Haciendo la tarea                                     *
 * Url: https://acm.javeriana.edu.co/maratones/2015/10              *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 26-09-2015                                                *
 *******************************************************************/

#include <map>
#include <cstdio>
using namespace std;

int main() {
	int a,b,rta;
	map<int,int> inv;
	scanf("%d", &a);
	while(a != 0){
		rta++;
		b = a;
		inv.clear();
		while(b > 0){
			inv[b%10]++;
			b/=10;
		}
		b=0;
		for(map<int,int>::iterator it = inv.begin(); it != inv.end(); ++it){
			for(int i=0;i<it->second;i++){
				b*=10;
				b+= it->first;
			}
		}
		a = a-b;
		
	}
	printf("%d\n",rta);
	
	return 0;
}

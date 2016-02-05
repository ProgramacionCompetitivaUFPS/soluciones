/********************************************************************
 * Ejercicio: A Long, Long Time Ago                                 *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1962
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
using namespace std;

int main() {
	int casos, anio;
	scanf("%d", &casos);
	while(casos > 0){
		scanf("%d", &anio);
		anio = anio - 2015;
		if(anio >= 0){
			printf("%d A.C.\n", anio + 1);
		}else{
			printf("%d D.C.\n", anio * -1);
		}
		casos--;
	}
	return 0;
}
 

/********************************************************************
 * Ejercicio: Soccer Standings	                                    *
 * Url: https://acm.javeriana.edu.co/maratones/2015/12              *
 * Lenguaje: c++	                                                *
 * Autor: Bhaskara's Formulae (Melissa Delgado - Cristhian León -   *
 * Gerson Lázaro                                                    *
 * Fecha: 24-10-2015                                                *
 *******************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;

/*
Sing my angel of music
sing with me
*/

int main() {
	int i = 1, casos, puntos, partidos, g;
	scanf("%d", &casos);
	while(i <= casos){
		scanf("%d %d", &partidos, &puntos);
		printf("Team #%d\nGames: %d\nPoints: %d\nPossible records:\n", i, partidos, puntos);
		g = puntos / 3;
		g = min(g, partidos);
		while(puntos - g*3 <= partidos - g && g >= 0){
			printf("%d-%d-%d\n", g, (puntos-g*3), (partidos-g- (puntos-g*3)));
			g--;
		}
		printf("\n");
		i++;
	}
	return 0;
}
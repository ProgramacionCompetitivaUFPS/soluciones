/********************************************************************
 * Ejercicio: A - Bounding box	                                    *
 * Lenguaje: c++                                          			*
 * Autor: UFPSTeamLeader (Gerson Lázaro - Melissa Delgado)          *
 * Fecha: 18-02-2017                                                *
 * Comentarios: Aceptado en UVA.                                    *
 *******************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct point { 
	double x, y;
  	point() { 
  		x = y = 0.0; 
  	}
  	point(double _x, double _y) : x(_x), y(_y) {}        
  	bool operator == (point other) const {
   		return (fabs(x - other.x) < 1e-9 && (fabs(y - other.y) < 1e-9)); 
   	}
};

int main() {
	int n;
	double a, b;
	cin >> n;
	int poligono = 1;
	while(n > 0) {
		double xmax, xmin, ymax, ymin;
		point puntos[3];
		for(int i = 0; i < 3; i++) {
			cin >> a >> b;
			puntos[i] = point(a, b);
		}
		double recta1[3], recta2[3];
		recta1[0] = 2 * puntos[0].x - 2 * puntos[1].x;
		recta1[1] = 2 * puntos[0].y - 2 * puntos[1].y;
		recta1[2] = puntos[1].x * puntos[1].x + puntos[1].y * puntos[1].y - puntos[0].x * puntos[0].x - puntos[0].y * puntos[0].y;
		recta2[0] = 2 * puntos[2].x - 2 * puntos[1].x;
		recta2[1] = 2 * puntos[2].y - 2 * puntos[1].y;
		recta2[2] = puntos[1].x * puntos[1].x + puntos[1].y * puntos[1].y - puntos[2].x * puntos[2].x - puntos[2].y * puntos[2].y;
		
		double xc = (recta2[2] * recta1[1] - recta1[2] * recta2[1]) / (recta1[0] * recta2[1] - recta2[0] * recta1[1]);
		double yc = (-1 * recta1[0] * xc - recta1[2]) / recta1[1];
		point centro = point(xc, yc);
		double angulo = 2.0 * acos(-1.0) / (double)n;
		double nx, ny;
		xmin = puntos[0].x;
		xmax =puntos[0].x;
		ymin = puntos[0].y;
		ymax = puntos[0].y;
		nx = puntos[0].x;
		ny = puntos[0].y;
		double nx2, ny2;
		for(int i = 1; i < n; i++) {
			nx2 = ((nx - centro.x)* cos(angulo) - (ny - centro.y) * sin(angulo)) + centro.x;
			ny2 = ((nx - centro.x)* sin(angulo) + (ny - centro.y) * cos(angulo)) + centro.y;
			nx = nx2;
			ny = ny2;
			xmin = min(xmin, nx);
			xmax = max(xmax, nx);
			ymin = min(ymin, ny);
			ymax = max(ymax, ny);
		}
		
		printf("Polygon %d: %.3lf\n", poligono++, (xmax - xmin) * (ymax - ymin));
		
		cin >> n;
		
		
	}
	return 0;
}
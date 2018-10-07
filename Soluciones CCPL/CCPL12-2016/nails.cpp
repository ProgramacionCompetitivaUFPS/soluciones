/********************************************************************
 * Ejercicio:  I - Nails                                            *
 * Lenguaje: c++                                                    *
 * Autor: Wingardium Leviosa (Melissa Delgado - Daniel Vega -       *
 * Gerson Lázaro                                                    *
 * Fecha: 22-10-2016                                                *
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

struct vec { 
	double x, y;  
  	vec(double _x, double _y) : x(_x), y(_y) {} 
};

vec toVector(point a, point b) {       
	return vec(b.x - a.x, b.y - a.y); 
}

double angle(point a, point b, point c) { 
  	vec ba = toVector(b, a);
  	vec bc = toVector(b, c);
  	return acos((ba.x * bc.x + ba.y * bc.y) / sqrt((ba.x * ba.x + ba.y * ba.y) * (bc.x * bc.x + bc.y * bc.y))); 
}

 double cross(vec a, vec b) { 
	return a.x * b.y - a.y * b.x; 
}

bool ccw(point p, point q, point r) {
    return cross(toVector(p, q), toVector(p, r)) > 0; 
}

bool inPolygon(point pt, vector<point> P) {
	if (P.size() == 0){
  		return false;
  	} 
  	double sum = 0;    
  	for (int i = 0; i < P.size()-1; i++) {
    	if (ccw(pt, P[i], P[i+1])){
    		sum += angle(P[i], pt, P[i+1]); 
    	}else{
    		sum -= angle(P[i], pt, P[i+1]);
    	}
    }
  	return fabs(fabs(sum) - 2*acos(-1.0)) < 1e-9; 
}

double euclideanDistance(point p1, point p2) {           
  return hypot(p1.x - p2.x, p1.y - p2.y); 
} 


bool collinear(point p, point q, point r) {
	return fabs(cross(toVector(p, q), toVector(p, r))) < 1e-9; 
}

point pivot;
bool angleCmp(point a, point b) {                
	if (collinear(pivot, a, b)){
		return euclideanDistance(pivot, a) < euclideanDistance(pivot, b);
	}                              
        
  	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; 
}


vector<point> convexHull(vector<point> P) {  
  	int i, j, n = P.size();
  	if (n <= 3) {
    	if (!(P[0] == P[n-1])){
    		P.push_back(P[0]);
    	}  
    	return P;
  	}
  	int P0 = 0;
  	for (i = 1; i < n; i++){
  		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)){
  	 		P0 = i;
  	 	}
  	}

  	point temp = P[0]; P[0] = P[P0]; P[P0] = temp; 
	pivot = P[0];
  	sort(++P.begin(), P.end(), angleCmp);     
	vector<point> S;
  	S.push_back(P[n-1]); 
  	S.push_back(P[0]); 
  	S.push_back(P[1]);   
  	i = 2;                                         
  	while (i < n) {           
    	j = S.size()-1;
    	if (ccw(S[j-1], S[j], P[i])){
    		S.push_back(P[i++]);
    	}else{
    		S.pop_back();
    	}  
    }  
  	return S; 
}  

double perimeter(vector<point> P) {
	double result = 0.0;
  	for (int i = 0; i < P.size()-1; i++){
    	result += euclideanDistance(P[i], P[i+1]);
  	}
  	return result; 
}


int main() {
	int n, a, b, x, y;
	scanf("%d", &n);
	vector<point> p;
	while(n-- > 0) {
		p.clear();
		scanf("%d %d", &a, &b);
		for(int i = 0; i < b; i++ ) {
			scanf("%d %d", &x, &y);
			p.push_back(point(x,y));
		}
		
		printf("%.5lf\n", max((double)a, perimeter(convexHull(p))));
	}
	return 0;
}
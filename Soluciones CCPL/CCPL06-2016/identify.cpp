/********************************************************************
 * Ejercicio:  I - Identifying Map Tiles	                        *
 * Lenguaje: c++                                                    *
 * Autor: Si WA Meli nos golpea (Melissa Delgado - Daniel Vega -    *
 * Gerson Lázaro                                                    *
 * Fecha: 04-06-2016                                                *
 *******************************************************************/

 #include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int i, x, y, n, dx, dy, c, cuad;
	
	
	while(cin>>s){
		n = s.size();

		c = pow(2, s.size() ) / 2;
		
		cuad = s[0] - '0';
		dx = dy = 0;
		
		if(cuad == 1){
			dy = 1;
		}else if(cuad == 2){
			dx = 1;
		}else if(cuad == 3){
			dx = 1;
			dy = 1;
		}
		x = (dx * c);
		y = (dy * c);
		
		if(s.size()>1){
			for(i=1; i<s.size(); i++){
				// cout<<x<<" "<<y<<endl;
				dx = dy = 0;
				c = pow(2, s.size()-i) / 2;	
				cuad = s[i] - '0';
				if(cuad == 1){
					dy = 1;
				}else if(cuad == 2){
					dx = 1;
				}else if(cuad == 3){
					dx = 1;
					dy = 1;
				}
				x += (dx * c);
				y += (dy * c);
			}
		}
		
		
		cout<<n<<" "<<y<<" "<<x<<"\n";
	}
	return 0;
}
/********************************************************************
 * Ejercicio: Wheels                                                *
 * Url: https://cerc.tcs.uj.edu.pl/2014/data/d.pdf                  *
 * Lenguaje: c++                                                    *
 * Autor: Bhaskara's Formulae (Gerson Lázaro - Melissa Delgado -    *
 * Cristhian León)                                                  *
 * Fecha: 17-10-2015                                                *
 *******************************************************************/

#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

int valores[1004][6];
int numero = 0;
queue<int> pendientes;

int mcd(int a, int b) {
	int aux;
	while(b!=0){
		a %= b;
		aux = b;
		b = a;
		a = aux;
	}
	return a;
}

void simplificar(int num, int den, int i){
	int mc = mcd(num, den);
	valores[i][3] = num / mc;
	valores[i][4] = den / mc;
}

void backtracking(int pos){
	for(int i = 0; i < numero; i++){
		if(i != pos && valores[i][5] == -1){
			if(sqrt(pow(valores[pos][0]-valores[i][0],2)+pow(valores[pos][1]-valores[i][1],2)) == valores[i][2]+valores[pos][2]){
				pendientes.push(i);
				if(valores[pos][5] == 1){
					valores[i][5] = 2;
				}else{
					valores[i][5] = 1;	
				}
				simplificar(valores[pos][2]*valores[pos][3], valores[pos][4]*valores[i][2], i);
			}
		}
	}
	if(!pendientes.empty()){
		int aux = pendientes.front();
		pendientes.pop();
		backtracking(aux);
	}
}


int main() {
	int i, casos;
	scanf("%d", &casos);
	while(casos > 0){
		scanf("%d", &numero);
		for(i = 0; i < numero; i++){
			scanf("%d %d %d", &valores[i][0], &valores[i][1], &valores[i][2]);
			valores[i][3] = -1;
			valores[i][4] = -1;
			valores[i][5] = -1;
		}
		valores[0][3] = 1;
		valores[0][4] = 1;
		valores[0][5] = 1;
		backtracking(0);
		for(i = 0; i < numero; i++){
			if(valores[i][5] == -1){
				printf("not moving\n");
			}else{
				if(valores[i][4] == 1){
					printf("%d", valores[i][3]);
				}else{
					printf("%d/%d", valores[i][3], valores[i][4]);
				}
				if(valores[i][5] == 1){
					printf(" clockwise\n");
				}else{
					printf(" counterclockwise\n");
				}
			}
		}
		casos--;
	}
	return 0;
}

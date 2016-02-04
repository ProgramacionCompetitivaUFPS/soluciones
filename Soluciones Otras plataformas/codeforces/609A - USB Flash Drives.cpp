/********************************************************************
 * Ejercicio: USB Flash Drives                                      *
 * Url: http://codeforces.com/problemset/problem/609/A              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> usb;
	int cant, tam, b;
	scanf("%d %d", &cant, &tam);
	for(int i = 0; i < cant; i++){
		scanf("%d", &b);
		usb.push_back(b);
	}
	sort(usb.begin(), usb.end());
	for(int i = cant - 1, j = 1; i >= 0; i--, j++){
		tam -= usb[i];
		if(tam <= 0){
			printf("%d\n", j);
			break;
		}
	}
	return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> pesos,rta;

void llenar(){
	int i=0,expo=1;
	while(pesos[i]<10000000){
		pesos.push_back(pow(3,expo));
		expo++;
		i++;
	}
}
void calcular(int peso){
	rta.clear();
	int i=0;
	for(;i<pesos.size();i++){
		if(pesos[i]>peso) break;
	}
	i--;

	while(i>=0){
		rta.push_back(peso/pesos[i]);
		peso %= pesos[i];
		i--;
	}
}


int main() {
	pesos.push_back(1);
	llenar();
	int n,peso,i;
	cin >> n;
	while(n>0){
		cin >> peso;
		calcular(peso);
		for(i=0;i<rta.size();i++){
			cout << rta[i];
			if(i+1<rta.size()){
				cout << " ";
			}else{
				cout << "\n";
			}
		}
		n--;
	}
	return 0;
}
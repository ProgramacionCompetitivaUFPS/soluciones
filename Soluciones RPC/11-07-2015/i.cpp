#include <cstdio>
using namespace std;

int main() {
	int a1,b1,a2,b2, dif1, dif2, i, aux, j=0;
	double rta1, rta2;
	
	while(j<2){
	
	scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
	
	dif1=b1-a1;
	dif2=b2-a2;
	dif1++;
	dif2++;
	if(dif1>dif2){
		aux=0;
		for(i=a1; i<=b1; i++){
			aux+=(i+a2);
		}
		
		rta2=0;
		i=a2+1;
		rta2=(double)aux;
		while(i<=b2){
			aux+=dif1;
			rta2+=aux;
			i++;
		}
	}else{
		aux=0;
		for(i=a2; i<=b2; i++){
			aux+=(i+a1);
		}
		
		rta2=0;
		i=a1+1;
		rta2=aux;
		while(i<=b1){
			aux+=dif2;
			rta2+=aux;
			i++;
		}
		
	}
	
	rta2/=(double)((dif1)*(dif2));
		if(j==0){
			rta1=rta2;
		}
		j++;
	}
	
	if(rta1>rta2){
		printf("Gunnar\n");
	}else if(rta1==rta2){
		printf("Tie\n");
	}else{
		printf("Emma\n");
	}
	
	
	
	
	return 0;
}
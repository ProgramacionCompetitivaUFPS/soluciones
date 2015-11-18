/****************************************************************************************************
 * Ejercicio: At most twice                                   										*
 * Url: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=702	*            *
 * Lenguaje: c++	                                              								  	*
 * Autor: Candelaria (Melissa Delgado - Cristhian León -  Gerson Lázaro)                          	*                        *
 * Fecha: 14-11-2015                                                								*
 ***************************************************************************************************/

 #include <bits/stdc++.h>

using namespace std;

int main(){
	string num;
	int aux;
	int pos, i;
	map<int,int> digits;
	while(cin>>num){
		pos=0;
		digits.clear();
		for(i=0; i<num.size(); i++){
			aux=(int)num[i]-48;
			digits[aux]++;
			if(digits[aux]>2){
				pos=i;
				break;
			}
		}
		
		if(i==num.size()){
			cout<<num<<"\n";
		}else{
			for(i=pos; i>=0; i--){
				aux=(int)num[i]-48;
				digits[aux]--;
				aux--;
				while(aux>=0){
					if(digits[aux]<2){
						break;
					}
					aux--;
				}
				if(aux!=-1){
					digits[aux]++;
					num[i]=(char)(aux+48);
					pos=i+1;
					break;
				}
			}
		
			aux=9;
		
			for(i=pos; i<num.size(); i++){
				while(digits[aux]==2){
					aux--;
				}
				digits[aux]++;
				num[i]=(char)(aux+48);
			}
		
			if(num[0]=='0'){
				num.erase(0,1);
			}
		
			cout<<num<<"\n";
		}
	}
}
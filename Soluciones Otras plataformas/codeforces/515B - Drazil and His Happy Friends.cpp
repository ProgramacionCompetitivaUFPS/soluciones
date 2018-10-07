/********************************************************************
 * Ejercicio: Drazil and His Happy Friends                          *
 * Url: http://codeforces.com/problemset/problem/515/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <cstdio>
using namespace std;

int MOD = 1e9+7;
int valores[105];


int gcd(int a, int b) {
    int aux;
    while(b!=0){
        a %= b;
        aux = b;
        b = a;
        a = aux;
    }
    return a;
}

int main(){
    int i,n,m,b,aux,g;
    scanf("%d %d %d", &n, &m, &b);
    int mcd= gcd(n,m);
    for(i = 0; i < b; i++){
        scanf("%d", &aux);
        valores[aux % mcd] = 1;
    }
    scanf("%d", &g);
    for(i = 0; i < g; i++){
        scanf("%d", &aux);
        valores[aux % mcd] = 1;
    }
    for(i = 0; i < mcd; i++){
        if(valores[i] == 0){
            printf("No\n");
            goto fin;
        }
    }
    
    printf("Yes\n");
    fin:
    return 0;
}
 

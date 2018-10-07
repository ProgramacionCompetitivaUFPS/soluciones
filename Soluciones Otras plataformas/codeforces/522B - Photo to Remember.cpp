/********************************************************************
 * Ejercicio: Photo to Remember                                     *
 * Url: http://codeforces.com/problemset/problem/522/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 30-11-2015                                                *                                                                   *
 *******************************************************************/

#include <cstdio>
using namespace std;

int main() {
    int i, num;
    int mayorAltura = 0, sumaAncho = 0, ma2 = 0;
    int acum;
    scanf("%d", &num);
    int vec[num][2];
    for(i = 0; i < num; i++){
        scanf("%d %d", &vec[i][0], &vec[i][1]);
        sumaAncho += vec[i][0];
        if(vec[i][1] >= mayorAltura){
            ma2 = mayorAltura;
            mayorAltura = vec[i][1];
        }else if(vec[i][1] > ma2){
            ma2 = vec[i][1];
        }
    }
    for(i = 0; i < num; i++){
        acum = sumaAncho - vec[i][0];
        if(mayorAltura == vec[i][1]){
            acum *= ma2;
        }else{
            acum *= mayorAltura;
        }
        printf("%d", acum);
        if(i+1 < num){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}

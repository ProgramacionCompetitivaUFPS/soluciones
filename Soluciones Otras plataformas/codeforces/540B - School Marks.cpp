/********************************************************************
 * Ejercicio: School Marks                                          *
 * Url: http://codeforces.com/problemset/problem/540/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k,p,x,y, menores = 0, suma = 0,aux;
    cin >> n >> k >> p >> x >> y;
    for(int i=0; i < k; i++){
        cin >> aux;
        if(aux<y){
            menores++;
        }
        suma += aux;
    }
    suma = x - suma;
    if(suma <= 0 || menores > n/2){
        cout << "-1\n";
        return 0;
    }
    string rta;
    k++;
    for(; menores < n/2 && k <= n; menores++, k++){
        rta+= "1";
        suma -= 1;
        if(k != n){
            rta+= " ";
        }else{
            rta+= "\n";
        }
    }
    for(; k <= n; k++){
        rta += to_string(y);
        suma -=y;
        if(k != n){
            rta+= " ";
        }else{
            rta+= "\n";
        }
    }
    if(suma >= 0){
        cout << rta;
    }else{
        cout << -1 << "\n";
    }
    return 0;
}

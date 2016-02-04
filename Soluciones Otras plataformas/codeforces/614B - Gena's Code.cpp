/********************************************************************
 * Ejercicio: Gena's Code                                           *
 * Url: http://codeforces.com/problemset/problem/614/B              *
 * Lenguaje: c++                                                    *
 * Autor: Gerson Lázaro                                             *
 * Fecha: 04-02-2016                                                * 
 *******************************************************************/
 
#include <iostream>
using namespace std;

int main() {
    int n, cerosT = 0, cerosP = 0;
    cin >> n;
    string num = "1";
    string pal;
    bool cero = false, unos = false, otro = false;
    for(int i = 0, j = 0; i < n; i++){
        cin >> pal;
        cerosP = 0;
        unos = false;
        otro = false;
        if(!cero){
            for(j = 0; j < pal.length();j++){
                if((unos && pal[j] == '1') || (pal[j] < 48 || pal[j] > 49)){
                    num = pal;
                    otro = true;
                    break;
                }
                if(j == 0 && pal[0] == '0'){
                    cero = true;
                }
                if(pal[j] == '1'){
                    unos = true;
                }else{
                    cerosP++;
                }
            }
            if(!otro){
                cerosT += cerosP;
            }
        }
    }
    if(cero){
        cout << "0\n";
    }else{
        string m = num;
        for(int i = 0; i < cerosT; i++){
            m += "0";
        }
        cout << m << "\n";
    }
    return 0;
}

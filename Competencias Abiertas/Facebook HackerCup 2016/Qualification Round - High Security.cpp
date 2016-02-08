/*********************************************************************
 * Ejercicio: High Security                                          *
 * Url: https://www.facebook.com/hackercup/problem/1527664744192390/ *
 * Lenguaje: c++                                                     *
 * Autor: Melissa Delgado                                            *
 * Fecha: 08-02-2016                                                 * 
 ********************************************************************/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int place[2][1005];
int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ifstream cin("high_security.txt");
    ofstream cout("salida.txt");

    int tc, cont, k, i, j, rta;
    char aux;
    bool flag;
    cin>>tc;
    k=1;
    while(k<=tc){
        cin>>n;
        cont=0;
        rta=0;

        for(i=0; i<n; i++){
            cin>>aux;
            if(aux=='X'){
                place[0][i]=0;
                cont=0;
            }else{
                cont++;
                place[0][i]=cont;
                if(cont==1){
                    rta++;
                }
            }
        }

        cont=0;
        flag=true;

        for(i=0; i<n; i++){
            cin>>aux;
            if(aux=='X'){
                place[1][i]=0;
                cont=0;

                if(flag && i>0 && place[1][i-1]==1 && place[0][i-1]!=0){
                    j=i-1;

                    while(j<n && place[0][j]!=0){
                        place[0][j]=0;
                        j++;
                    }
                    rta--;
                }
                flag=true;

            }else{
                cont++;
                place[1][i]=cont;

                if(cont==1){
                    rta++;
                }
                if(flag && i<n-1 && place[0][i]==1 && place[0][i+1]==0){
                    rta--;
                    flag=false;
                }
            }
        }

        if(place[1][n-1]!=0){
            if(place[1][n-1]==1){
                if(place[0][n-1]!=0){
                    rta--;
                }
            }else if(flag && place[0][n-1]==1){
                rta--;
            }
        }

        cout<<"Case #"<<k<<": "<<rta<<endl;

        k++;
    }

    return 0;
}

#include <stdio.h>
#include <algorithm> 
#include <vector>
#define endl "\n"

/**
 * @author Bashkara's Formulae (team Candelaria):
 *      Gerson Lázaro - Melissa Delgado - Cristhian León
 *      UFPS
*/

using namespace std;

vector<int> f (100,0);
vector<int> s (100,0);

int main(){
    int tc,n, i, j;   
    long long m, l;
    scanf("%i", &tc);

    while(tc>0){
        scanf("%i", &n);
        i=0;
        m=l=0;

        for(; i<n; i++){
            scanf("%i", &s[i]);
        }

        for(i=0; i<n; i++){
            scanf("%i", &f[i]);
        }
        
        for(i=0; i<n; i++){
            for(j=0; j<n && f[i]!=0; j++){
                m+=min(f[i], s[j]);
            }
        }
        
        if(n>1){
            sort(s.begin(), s.begin()+n);
            sort(f.begin(), f.begin()+n);
        }

        i=j=0;
        while ((j < n) && (i < n)){
          if (f[j] == s[i])
          {
            l += f[j];
            j++;
            i++;
          } 
          else if (f[j] < s[i])
            l += f[j++];
          else
            l += s[i++];
        }
        while (j < n)
          l += f[j++];
        while (i < n)
          l += s[i++];

        printf("Minimalni budova obsahuje %lld kostek, maximalni %lld kostek.\n", l, m);
        tc--;
    }

}
/** 719A - Vitya in the Countryside 
  * http://codeforces.com/problemset/problem/719/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, act = -20, ant;
  scanf("%d", &n);
  while(n--) {
    ant = act;
    scanf("%d", &act);
  }
  if(act == 15) printf("DOWN\n");
  else if(act == 0) printf("UP\n");
  else if(ant + 1 == act) printf("UP\n");
  else if(ant - 1 == act) printf("DOWN\n");
  else printf("-1\n");
  return 0;
}
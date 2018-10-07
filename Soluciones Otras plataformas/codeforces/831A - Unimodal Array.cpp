/** 831A - Unimodal Array 
  * http://codeforces.com/problemset/problem/831/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, prev = 0, act, step = 0;
  bool flag = true;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &act);
    if(step == 0 && act > prev);
    else if(step == 0 && act == prev) step++;
    else if(step == 0 && act < prev) step += 2;
    else if(step == 1 && act == prev);
    else if(step == 1 && act < prev) step++;
    else if(step == 2 && act < prev);
    else flag = false;
    prev = act;
  }
  if(flag) printf("YES\n");
  else printf("NO\n");
  return 0;
}
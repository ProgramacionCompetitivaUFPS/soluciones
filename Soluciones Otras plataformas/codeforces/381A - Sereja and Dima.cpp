/** 381A - Sereja and Dima
  * http://codeforces.com/problemset/problem/381/A
  * Category: Greedy
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, aux, sereja = 0, dima = 0;
  scanf("%d", &n);
  deque<int> vals;
  while(n--) {
    scanf("%d", &aux);
    vals.push_back(aux);
  }
  bool player1 = true;
  while(!vals.empty()) {
    if(player1) sereja += max(vals.front(), vals.back());
    else dima += max(vals.front(), vals.back());
    if(vals.front() > vals.back()) vals.pop_front();
    else vals.pop_back();
    player1 = !player1;
  }
  printf("%d %d\n", sereja, dima);
  return 0;
}
/** 546C - Soldier and Cards
  * http://codeforces.com/problemset/problem/546/C
  * Category: Brute Force
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int t, a, b, ans;
  scanf("%d", &t);
  set<pair<queue<int>, queue<int> > > visit;
  scanf("%d", &a);
  queue<int> one, two;
  while(a--) {
    scanf("%d", &b);
    one.push(b);
  }
  scanf("%d", &a);
  while(a--) {
    scanf("%d", &b);
    two.push(b);
  }
  visit.insert(make_pair(one, two));
  pair<queue<int>, queue<int> > aux;
  ans = 0;
  while(!one.empty() && !two.empty()) {
    a = one.front(); one.pop();
    b = two.front(); two.pop();
    ans++;
    if(a > b) {
      one.push(b); one.push(a);
    } else {
      two.push(a); two.push(b);
    }
    aux = make_pair(one, two);
    if(visit.count(aux)) {
      printf("-1\n");
      return 0;
    }
    visit.insert(aux);
  }
  printf("%d ", ans);
  if(one.empty()) printf("2\n");
  else printf("1\n");
  return 0;
}
/** 82A - Double Cola
  * http://codeforces.com/problemset/problem/82/A
  * Category: Math, Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  int n, limit = 5, increment = 5, limitPrev = 0, cant = 1;
  cin >> n;
  while(limit < n) {
    increment *= 2;
    cant *= 2;
    limitPrev = limit;
    limit += increment;
    }
  n -= limitPrev;
  n = ceil((double)n/cant);
  cout << names[n - 1] << endl;
  return 0;
}
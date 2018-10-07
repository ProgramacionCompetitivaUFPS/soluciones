/** 405A - Gravity Flip
  * http://codeforces.com/problemset/problem/405/A
  * Category: Greedy, Sorting
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
  sort(arr, arr + n);
  printf("%d", arr[0]);
  for(int i = 1; i < n; i++) printf(" %d", arr[i]);
  printf("\n");
  return 0;
}
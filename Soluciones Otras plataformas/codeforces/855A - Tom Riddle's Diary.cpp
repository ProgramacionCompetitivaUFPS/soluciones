/** 855A - Tom Riddle's Diary
  * http://codeforces.com/problemset/problem/855/A
  * Category: Implementation
  */

#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  string s;
  set<string> words;
  while(n--) {
    cin >> s;
    if(!words.count(s)) cout << "NO\n";
    else cout << "YES\n";
    words.insert(s);
  }
  return 0;
}
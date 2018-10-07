/** 230B - T-primes
  * http://codeforces.com/problemset/problem/230/B
  * Category: Math
  */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
vector<int> primes;
set<long long> tprimes;
bool sieve[MAX+5];

void calculatePrimes() {
  sieve[0] = sieve[1] = 1;
  int i;
  for (i = 2; i * i <= MAX; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      tprimes.insert((long long)i * (long long)i);
      for (int j = i * i; j <= MAX; j += i) sieve[j] = true;
    }
  }
  for(;i <= MAX; i++){
  	if (!sieve[i]) {
      primes.push_back(i);
      tprimes.insert((long long)i * (long long)i);
  	}
  }
}


int main () {
  calculatePrimes();
  int n;
  long long c;
  cin >> n;
  while(n--) {
    cin >> c;
    if(tprimes.count(c)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7
#define MAXN 125257

const int MOD = 1000000007;

/*
  This function calculates the modular inverse.

  To calculate the following equation, call this function.
  (a/b) % MOD

  (a * modularBinaryExponentiation(b, MOD-2)) % MOD;
*/

ll modularBinaryExponentiation(int base, int exponent) {
  if(exponent == 0) 
    return 1;

  ll result = modularBinaryExponentiation(base, exponent/2);

  if (exponent%2 == 1)
    return (((result * result) % MOD) * base ) % MOD;
  
  else 
    return (result  * result) % MOD;
}

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

/*
  This is a simple 1d problem. Refer to possible_sums_dp.cpp in implementation folder

  
*/

void run() {
  int n;

  cin>>n;
  
  int totalSum = (n * (n + 1))/2;

  if (totalSum % 2) {
    cout<<0<<endl;
    return;
  }

  int setSum = totalSum/2;
  vector<ll> dp(setSum+1);
  
  dp[0] = 1;
  for(int i=1;i<=n;i++) {
    for(int sum = setSum;sum>=i;sum--) {
      dp[sum] =  (dp[sum] + dp[sum - i]) % MOD;
    } 
  }

  cout<< (dp[setSum] * modularBinaryExponentiation(2, MOD-2)) % MOD;
}

int main() {    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

}

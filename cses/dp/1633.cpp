#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define MAXN  1e6

vector<ll> ans(MAXN);

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}
/*
  Type: DP + MEMOIZATION
  
  This problem can be simply solved using top - down approach
  along with memoization

  1. How many states will be there in my dp ?
  -> 1

  2. What does each state in my dp represent ?
  -> dp[i] represents number of ways i can be created by throwing a dice

  3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?
  -> for all dice outcomes:
  ->    sum = (sum + solve(n-outcome))

*/
ll solve(int n) {
  if (n < 0) {
    return 0;
  }

  if (n == 0) {
    return 1;
  }

  if (ans[n] != 0) {
    return ans[n];
  }

  ll sum = 0;

  for(int i=1;i<=6;i++) {
    sum= (sum + solve(n-i))%MOD;
  }

  ans[n] = sum;
  return sum;
}

void run() {
  int n;

  cin>>n;

  ll ans = solve(n);

  cout<<((ans% MOD))<<endl;
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  // auto start = high_resolution_clock::now();
  
  run();
  
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

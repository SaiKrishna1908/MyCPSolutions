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

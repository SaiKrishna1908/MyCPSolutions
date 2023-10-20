#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  int n;

  cin>>n;

  vector<int> h(n);

  for(int i=0;i<n;i++) {
       cin>>h[i];
  }

  // The only thing that matters is where we are.
  vector<int> dp(n);

  // Dp state state represent the minimum cost to arrive at stone i
  fill(dp.begin(), dp.end(), 0);

  dp[0] = 0;
  dp[1] = abs(h[1]-h[0]);

  for(int i=2;i<n;i++) {
    dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]) , dp[i-2] + (abs(h[i] - h[i-2])));
  }

  cout<<dp[n-1];
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

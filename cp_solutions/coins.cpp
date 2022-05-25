#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  /*
    1. How many states will be there in my dp ?

    -> There will be two states in my dp

    2. What does each state in my dp represent ?

    -> dp[i][j] represents the probability to get i heads for j coins
    
    3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?

    -> dp[i][j] = dp[i-1][j] * (1-p_head) + dp[i-1][j-1] * (p_head) 
  */

  int n;

  cin>>n;

  vector<vector<double>> dp(n+1, vector<double>(n+1,0));

  dp[0][0] = 1;

  vector<double> p_heads(n);

  for(int i=0;i<n;i++) {
    cin>>p_heads[i];
  }

  for(int i=1;i<=n;i++) {
    for(int j=0;j<=i;j++) {

      if (j==0) {
        dp[i][j] = dp[i-1][j] * (1.0-p_heads[i-1]);
      } else {
        dp[i][j] = dp[i-1][j] * (1.0-p_heads[i-1]) +  dp[i-1][j-1] * (p_heads[i-1]);
      }      
    }
  }

  double sum  = 0.0;

  for(int heads=0;heads<=n;heads++) {
    if (heads > n-heads) {
      sum+=dp[n][heads];
    }
  }
  cout<<sum<<endl;
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
  std::cout << std::setprecision(10);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

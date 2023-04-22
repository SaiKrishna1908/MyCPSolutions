#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int n,m;
  cin>>n>>m;

  // vector<vector<int>> dp(n+1, vector<int>(m+1));
  int dp[n+1][m+1];

  memset(dp, INF, sizeof(dp));

  for(int i=1;i<=min(n,m);i++) {
    dp[i][i] = 0;
  }

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=m;j++) {
      // cut j

      for(int cj=1;(j-cj)>0;cj++) {
        dp[i][j] = min(dp[i][j], dp[i][j-cj]+dp[i][cj]+1);
      }

      // cut i
      for(int ci=1;(i-ci)>0;ci++) {
        dp[i][j] = min(dp[i][j], dp[i-ci][j]+dp[ci][j]+1);
      }
    }
  }

  cout<<dp[n][m]<<endl;
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

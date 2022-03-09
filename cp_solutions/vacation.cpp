#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  int n;

  cin>>n;

  vector<vector<ll>> hday(n, vector<ll>(3));

  for(int i=0;i<n;i++) {

      cin>>hday[i][0]>>hday[i][1]>>hday[i][2];
  }

  vector<vector<ll>> dp(n, vector<ll>(3));


  dp[0][0] = hday[0][0];
  dp[0][1] = hday[0][1];
  dp[0][2] = hday[0][2];

  for(int i=1;i<n;i++) {
      for(int j=0;j<3;j++) {

          dp[i][j] = hday[i][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
      }
  }
 
  cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;
}

int main() {

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

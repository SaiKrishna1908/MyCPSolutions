#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

const ll INF = 1e15+7;

// int getMin(int *arr) {
//   int minx = arr[0];
//   for(int i=1;i<arr.size();i++) {
//     if (arr[i] < minx) {
//       minx = arr[i];
//     }
//   }

//   return minx;
// }
void run() {
  
  int n,k;

  cin>>n>>k;

  vector<long> h(n);

  for(int i=0;i<n;i++) {
       cin>>h[i];
  }

  // The thing that matters is where we are and how we got there.
  vector<vector<long>> dp(n, vector<long>(k));

 
  for(int i=0;i<n;i++) {
    for(int j=0;j<k;j++) {
      dp[i][j] = INF;
    }
  }

  
  dp[0][0] = 0;

  vector<long> minDp(n);
  
  minDp[0] = 0;

  for(int i=1;i<n;i++) {
    minDp[i] = INF;
  }

  for(int i=1;i<n;i++) {      
    for(int j=1;j<=k;j++) {      

      if (i-j >= 0) {                        
        dp[i][j-1] = min(dp[i][j-1], minDp[i-j] + (long) abs(h[i] - h[i-j]));                
      } 
    } 

    for(int j=1;j<=k;j++) {
      minDp[i] = min(minDp[i], dp[i][j-1]);
    }       
  }

  for(int i=0;i<n;i++) {
    cout<<minDp[i]<<endl;

  }

  // cout<<endl;
  // cout<<minDp[n-1]<<endl;
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

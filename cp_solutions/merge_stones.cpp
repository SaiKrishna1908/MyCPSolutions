#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void run() {
  int n,k;

  cin>>n>>k;

  if(n%(k-1) != 0) {
    cout<<-1<<endl; 
  }

  int stones[n];


  for(int i=0;i<n;i++ ) {
  	cin>>stones[i];
  }

  // Initilize dp stonesay. dp[i][j] contains the minimum cost of the 
  // merging stones from stones[i] to stones[j]

  int dp[n][n];

  // Stores prefix sum
  int prefix_sum[n+1];

  for(int i=0;i<n;i++) {
  	prefix_sum[i+1] = prefix_sum[i] + stones[i]; 
  }


  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      dp[i][j] = 0;
    }
  }

  // Iterate through dp and calculate dp[i][j]
  for(int l=k-1;l<n;l++) {
 	 for(int i=0,j=i+l;i<n && j<n;i++,j++) {

        // if k = n-1, dp[i][j] = stones[i] + stones[i+1] +... + a[j]
 	 	    if(l==k-1) {
          dp[i][j] = prefix_sum[j+1] - prefix_sum[i];
        } else {
          dp[i][j] = INT_MAX;
          for(int mid = i; mid<j;mid+=k-1) {
            dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
          }

          if(l%(k-1) == 0) {

            cout<<i<<" "<<j<<" "<<l<<endl;
            dp[i][j] += prefix_sum[j+1] - prefix_sum[i];
          }
        }
    }
	}

  cout<<dp[0][n-1]<<endl;
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

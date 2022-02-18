#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define INT_MAX 1e9

void run() {
  int n,k;

  cin>>n>>k;

  if(n%(k-1) != 0) {
    cout<<-1<<endl; 
  }

  int arr[n];


  for(int i=0;i<n;i++ ) {
  	cin>>arr[i];
  }

  // Initilize dp array. dp[i][j] contains the minimum cost of the 
  // merging stones from arr[i] to arr[j]

  int dp[n][n];

  // Stores prefix sum
  int prefix_sum[n+1];

  for(int i=0;i<n;i++) {
  	prefix_sum[i+1] = prefix_sum[i] + arr[i]; 
  }

  // Iterate through dp and calculate dp[i][j]
  for(int l=k-1;l<n;l++) {
 	 for(int i=0,j=i+l;i<n && j<n;i++,j++) {

        // if k = n-1, dp[i][j] = arr[i] + arr[i+1] +... + a[j]
 	 	    if(l=k-1) {
          dp[i][j] = prefix_sum[y+1] - prefix_sum[i];
        } else {
          dp[i][j] = INT_MAX;
          for(int mid = i; mid<j;mid+=k-1) {
            dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
          }

          if(l%k-1 == 0) {
            dp[i][j] == prefix_sum[y+1] - prefix_sum[i];
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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

const int MAX = 1e7+7;

/*
What are my states in my dp ?

Let dpi,j is the minimum time to drive between the two cities,
if we consider first i signs and have already removed j signs.
We also assume that the ith sign is taken.

How many states are there in my dp ?
We have 2 states dp[i][j]

How will I transition to new state, ie dp[i+1] = ?


*/

void run() {
  int n,l,k;

  cin>>n>>l>>k;

  int dp[n+1][k+1];

  int d[n];
  int a[n];


  for(int i=0;i<n;i++) {
    cin>>d[i];  // Coordinates of all signs
  }

  for(int i=0;i<n;i++) {
    cin>>a[i]; // Speed limits
  }

  for(int i=0;i<=n;i++) {
    for(int j=0;j<=k;j++) {
      dp[i][j] = MAX;
    }
  }

  dp[0][0]= 0;

  for(int i=1;i<n;i++) {
    dp[i][0] = dp[i-1][0] + (d[i] - d[i-1]) * a[i-1];
  }

  dp[n][0] = dp[n-1][0] + (l-d[n-1]) * a[n-1];

  // cout<<"$$$"<<dp[n-2][0]<<"$$$"<<endl;

  // cout<<"###"<<((l-d[n-1]) * a[n-1])<<"#####"<<endl;

  for(int i=0;i<n;i++) {
    for(int j=0;j<=k;j++) {
      for(int pos=i+1;pos<n;pos++) {

        // if (pos < i || dp[i][j] == MAX) {
        //   continue;
        // }

        dp[pos][j+pos-i-1] = min(dp[pos][j+pos-i-1], dp[i][j] + (d[pos] - d[i]) * a[i-1]);
      }
    }
  }

  for(int i=0;i<=n;i++) {
    for(int j=0;j<=k;j++) {
      cout<<(dp[i][j] + (l-d[n-1]) * a[i])<<" ";
    }
    cout<<endl;
  }
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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int t,n;

  cin>>t;

  while (t-->0) {
    cin>>n;

    int a[n];


    for(int i=0;i<n;i++) {
      cin>>a[i];
    }

    vector<int> dp(n+1,0);

    dp[0] = 0;
    dp[1] = a[1] < a[0];

    for(int i=2;i<n;i++) {  
      dp[i] = max(dp[i-1],dp[i-2] + (a[i-1] > a[i]));
    }

    cout<<dp[n-1]<<endl;  
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

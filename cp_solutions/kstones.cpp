#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int n,k;

  cin>>n>>k;

  vector<bool> dp(k+1);

  vector<int> a(n);

  for(int i=0;i<=n;i++) {
    cin>>a[i];
  }

  for(int stones=0;stones<=k;stones++) {
    for(int capacity_taken : a) {
      if (stones >= capacity_taken && !dp[stones - capacity_taken] ) {
        dp[stones] = true;
      }
    } 
  }

  if (dp[k]) {
    cout<<"First"<<endl;
  } else {
    cout<<"Second"<<endl;
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

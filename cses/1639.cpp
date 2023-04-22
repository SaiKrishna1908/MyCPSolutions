#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

#define MAXN 5007

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  string a;
  string b;

  cin>>a;
  cin>>b;

  int dp[a.length()][b.length()];  

  dp[0][0] = 0;

  bool mk1 = false, mk2 = false;

  if (a[0] == b[0]) {
    dp[0][0]= 0;
    mk1=true;
    mk2=true;
  } else {
    dp[0][0]=1;
  }

  for(int i=1;i<a.length();i++) {
    if (!mk1 && b[0] == a[i]) {
      dp[i][0] = dp[i-1][0];
      mk1 = true;
      continue;
    }
    dp[i][0] = dp[i-1][0] + 1;
  }
  for(int i=1;i<b.length();i++) {
    if (!mk2 && a[0] == b[i]) {
      dp[0][i] = dp[0][i-1];
      mk2=true;
      continue;
    }
    dp[0][i] = dp[0][i-1] + 1;
  }

  for(int i=1;i<a.length();i++) {
    for(int j=1;j<b.length();j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
      }
    }
  }

  // for(int i=0;i<a.length();i++) {
  //   for(int j=0;j<b.length();j++) {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  cout<<dp[a.length()-1][b.length()-1]<<endl;
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

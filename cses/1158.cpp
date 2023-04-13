#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

#define MAXN 100007

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

/*
  How many states will be there in dp ?
  -> 2 states

  What does each state in the dp represent ?
  -> dp[i][j] represents the maximum pages that can be bought using first i books and with a price of j.

  How do we transition to new state ?
  -> Each new state we need to check weather we need to consider the current book or not, hence the transition is as follows
  -> dp[i][j] = max (dp[i-1][j], pages[i] + dp[i-1][j-prices[i]] )

*/


void run() {
  int n, x;
  cin>>n>>x;
  
  vector<int> prices(n+1);
  vector<int> pages(n+1);

  for(int i=1;i<=n;i++) {
    cin>>prices[i];
  }

  for(int i=1;i<=n;i++) {
    cin>>pages[i];
  }

  vector<vector<int>> dp(n+1, vector<int> (MAXN));

  for(int i=1;i<=n;i++) {
    for(int j=1;j<=x;j++) {
      int temp_price = 0;
      if (j >= prices[i]) {
        temp_price = pages[i] + dp[i-1][j - prices[i]];
      }

      dp[i][j] = max(dp[i-1][j], temp_price);
    }
  }

  cout<<dp[n][x]<<endl;
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

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

/*

Type: Dp Tabulation
1. How many states will be there in my dp ?
-> 2D array.

2. What does each state in my dp represent ?
-> dp[i][j] represents the minimum cost for ith day performing jth activity

3. How do we transition to new state, i.e how do we compute dp[i][j]  using previous values ?
-> dp[i][j] = cost[i][j] + max(dp[i-1][j+1], dp[i-1][j+2])
   
*/

void run() {
  int n;

  cin>>n;

  vector<vector<int>> input;

  for(int i=0;i<n;i++) {
    int a,b,c;
    cin>>a>>b>>c;

    vector<int> vect{a,b,c};
    input.push_back(vect);
  }

  vector<vector<int>> dp(n, vector<int> (3));
  dp[0][0] = input[0][0];
  dp[0][1] = input[0][1];
  dp[0][2] = input[0][2];

  for(int i=1;i<n;i++) {
    for(int j=0;j<3;j++) {
      dp[i][j] = input[i][j] + max(dp[i-1][(j+1)%3] , dp[i-1][(j+2)%3]);
    }
  }


  cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
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

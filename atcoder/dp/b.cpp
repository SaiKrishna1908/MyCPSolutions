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
-> 1D array.

2. What does each state in my dp represent ?
-> dp[i] represents the minimum cost to reach ith stone

3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?
-> dp[new_stone] = min(dp[new_stone], dp[current_stone] + abs(cost(jump)))

   here new_stone can be current_stone+1, current_stone+2, current_stone+3... , current_stone+k
*/

void run() {
  int n,k;

  cin>>n>>k;

  vector<ll> v(n);
  

  for(int i=0;i<n;i++) {
    cin>>v[i];
  }

  vector<ll> dp(n, INF);

  dp[0] = 0;

  for(int i=0;i<n;i++) {
    for(int j=1;j<=k;j++) {
        int jump_stone = i+j;
        if (jump_stone < n) {
            dp[jump_stone] = min(dp[jump_stone], dp[i] + abs(v[i] - v[jump_stone]));
        }
    }
  }

  cout<<dp[n-1]<<endl;
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

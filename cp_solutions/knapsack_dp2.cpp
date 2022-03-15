#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

/*

1. How many states will be there in my dp ?
Ans. 1
2. What does each state in my dp represent ?
Ans. dp[i] represents the minimum weight to get value i
3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?

*/

const ll INF = 1e12;
void run() {
  
  int n,W;

  cin>>n>>W;


  vector<pair<int,int>> input(n);

  ll max_val = 0;

  for(int i=0;i<n;i++) {      
      int weight, value;
      cin>>weight>>value;
      auto p = make_pair(weight, value);
      

      input[i] = p;      
      max_val+=value;
  } 
  
  vector<ll> dp(max_val+1);

  fill(dp.begin(), dp.end(), INF);

  dp[0] = 0;
  for(int i=0;i<n;i++) {            
      auto current_pair = input[i];
      
      int current_value = current_pair.second;            
      
      for(int val = dp.size();val>=current_value;val--) {
        //   if (val-current_value != current_value && val != i){
              dp[val] = min(dp[val], dp[current_value] + dp[val-current_value]);
        //   } 
      }
     
  }

   for(int i=0;i<dp.size();i++) {
        cout<<"{"<<i<<", "<<dp[i]<<"} ";
      }

      cout<<endl;
  
   ll maxi_weight = 0;

      for(int i=0;i<dp.size();i++) {
          if (dp[i] <= W && maxi_weight <= i) {
              maxi_weight = i;
          }
      }

      cout<<maxi_weight<<endl;
  
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

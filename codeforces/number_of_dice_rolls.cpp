#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

// Given n number

// n = 3, k = 4, target = 5

/*
    
  1 + 2 + 2
  2 + 1 + 2
  2 + 2 + 1

  3 + 1 + 1
  1 + 3 + 1
  1 + 1 + 3

  


  How many dp states are required ? 1
  What are the dp states ? dp[i] represents the current sum till now

  
  []
  []
  []
*/ 
void run() {
  
  int n,k,t;

  cin>>n>>k>>t;

  // Dp with state 1
  vector<int> dp(t+1);

  // dp[i] represents the number of ways to get sum i  

  dp[0] = 1;

  for(int dices=0;dices<n;dices++) {

    vector<int> new_ways(t+1);

    // current_sum is the sum already present before the current dice is thrown
    for(int current_sum=0;current_sum<=t;current_sum++) {

      for(int dice_face = 1;dice_face <= k;dice_face++) {

         if (current_sum + dice_face <= t) {
            new_ways[current_sum + dice_face] += dp[current_sum]; 
         }
      }
    }

    dp = new_ways;
  }

  cout<<dp[t]<<endl;
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

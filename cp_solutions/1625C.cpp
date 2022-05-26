#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

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

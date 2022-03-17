#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

/*

1. How many states will be there in my dp ?
** There will be 2 states

2. What does each state in my dp represent ? 
** dp[i][j] represents the maximum 

3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?

*/

void display(vector<vector<int>> arr) {

    for(int i=0;i<arr.size();i++) {
        for(int j=0;j<arr[i].size();j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<"###########################"<<endl;
}

void run() {
  string s,t;
  cin>>s>>t;

  vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1,0));

//   fill(dp.begin(), dp.end(), 0);

// Why 

  for(int i=0;i<s.length();i++) {
      for(int j=0;j<t.length();j++) {
        if(s[i] == t[j]) {
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
        }
        dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      }

    //   display(dp);
  }

  int answer = 0;

  for(auto i : dp) {
      for(auto value : i) {
          answer = max(answer, value);
      }
  }


  cout<<answer<<endl;  
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

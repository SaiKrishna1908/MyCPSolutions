// https://codeforces.com/problemset/problem/245/H

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN 5000+10

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {  
  string input;

  cin>>input;

  int n = input.length();


  bool is_palindrome[MAXN][MAXN] = {{false}};
  int dp[MAXN][MAXN] = {{0}};

    
  for(int i=0;i<n;i++) {
    is_palindrome[i][i] = 1;
    dp[i][i] = 1;
    is_palindrome[i+1][i] = 1;
  }

  for(int len = 2;len <= n;len++) {
    for(int start = 0;(start + len) <= (n + 1);start++) {
      
      is_palindrome[start][start+len-1] = is_palindrome[start+1][start+len-2] & (input[start] == input[start+len-1]);
      dp[start][start+len-1] = dp[start][start+len-2] + dp[start+1][start+len-1] - dp[start+1][start+len-2] + is_palindrome[start][start+len-1];
    }
  }

  int q;
  cin>>q;
  

  while(q-->0) {
    int l,r;
    cin>>l>>r;
    cout<<dp[--l][--r]<<"\n";
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

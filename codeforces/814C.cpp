#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define MAXN 1502

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int n,q;
  cin>>n;

  string s;
  cin>>s;

  // dp[i][j] represents the max length of subsequence for i'th letter with m replacable count.
  int dp[26][MAXN] = {{0}};

  for(int c=0;c<26;c++) {
    char ch = c + 'a';
    for(int l=0;l<n;l++) {
      int not_match_count = 0;
      for(int r=l;r<n;r++) {
        if (s[r] != ch) not_match_count++;        
        dp[c][not_match_count] = max(dp[c][not_match_count], r-l+1);         
      }      
    }

    for(int i=1;i<=n;i++) {
        dp[c][i] = max(dp[c][i], dp[c][i-1]);
    }
  }

  

  cin>>q;

  for(int i=0;i<q;i++) {
    char c;
    int m;

    cin>>m>>c;

    int cindex = c - 'a';

    cout<<dp[cindex][m]<<endl;
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

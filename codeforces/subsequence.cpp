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
** dp[i][j] represents the maximum subsequence possible with string s of length s[0..i] and
    string t of length t[0..j].

3. How do we transition to new state, i.e how do we compute dp[i]  using previous values ?
** The transition rules are as follows:

  1. if s[i] == t[j]

        the following statements says that dp[i][j]
        is equal to 1 + maximum subsequence in s[i-1] t[j-1]

        dp[i][j] = dp[i-1][j-1] + 1
      else
        If they are not equal then max of dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        dp[i-1][j] --> exclude i character from string s
        dp[i][j-1] --> exclude j character from string t
*/

int dp[3001][3001];  


void run() {
  string s,t;
  cin>>s>>t;

  for(int i=1;i<=s.length();i++) {
      for(int j=1;j<=t.length();j++) {
        
        if (!i || !j) {
          dp[i][j] = 0;
        }

        // if i
        else if(s[i-1] == t[j-1]) {
            dp[i][j] = 1+ dp[i-1][j-1];
        }
        else {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

      }
  }

  int i=s.length(),j=t.length();
  
  string ans = "";

  while (i >0 && j>0) {    
    if (s[i-1] == t[j-1]) {      
      ans+=s[i-1];
      i--;
      j--;      
  } else {
    dp[i-1][j] > dp[i][j-1] ? (i--) : (j--);
    }
  }
  // cout<<dp[s.length()][t.length()]<<endl;  
  reverse(ans.begin(), ans.end());
  cout<<ans<<endl;

}

int main() {

  cin.tie(0)->sync_with_stdio(0);
  // cin.tie(0);
  // cin.sync_with_stdio(false);


  auto start = high_resolution_clock::now();

  run();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);
struct debug {
    
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return * this; }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return * this << range(begin(i), end(i)); }
    template < class c, class b > debug & operator <<(pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
    
};

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

int dp(vector<int> &v, vector<int> &w, int W) {

  int n = v.size();
  vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

  
  
  for(int i=0;i<=n;i++) {    
    for(int cw=0;cw<=W;cw++) {      
      if (i == 0 || cw == 0) {
        dp[i][cw] == 0;
      } else {
        if (w[i] > cw) {
          dp[i][cw] = dp[i-1][cw];
        } else {
          dp[i][cw] = max(dp[i-1][cw - w[i]] + v[i], dp[i-1][cw]);
        }
      }
    }
  }  

  return dp[n][W];
}


void run() {
  int W,n;  
  cin>>n>>W;

  vector<int> v(n+1),w(n+1);

  for(int i=1;i<=n;i++) {
    cin>>v[i];
  }

  for(int i=1;i<=n;i++) {
    cin>>w[i];
  }

  debug() << dp(v, w, W);
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

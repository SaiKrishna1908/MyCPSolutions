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

#define board vector<vector<char>>

vector<bool> col(8, false);
vector<bool> diag1(8, false);
vector<bool> diag2(8, false);

int ans = 0;
/**
 * Checking for diagonal violation r+c
 * [0,1,2,3]
 * [1,2,3,4]
 * [2,3,4,5]
 * 
 * Checking for column violation c
 * 
 * Checking for right diagonal violation r-c+7
*/

// According to pigeon-hole principal we need to put each queen in it's own row
void solve(int r, board &config) {    
  if (r == 8) {
    ans++;
    return;
  } else {    
    for(int c=0;c<8;c++) {
      // Check if we placing a queen at r,c is a violation
      if (col[c] || diag1[r+c] || diag2[r-c+7] || config[r][c] == '*') continue;      
      col[c] = diag1[r+c] = diag2[r-c+7] = true;
      solve(r+1, config);
      col[c] = diag1[r+c] = diag2[r-c+7] = false;
    }
  }
}

void run() {
  board config(8, vector<char>(8));

  int N = 8;

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin>>config[i][j];
    }
  }

  solve(0, config);
  cout<<ans<<endl;
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

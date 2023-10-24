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

vector<int> r(100, -1);

int memoized_rot_cut(vector<int> &profits, int n) {
  if (r[n] != -1) {
    return r[n];
  } 

  // Base case
  if (n == 0) {
    return 0;
  }

  int q = profits[n];

  for(int i=1;i<n;i++) {
    q = max(q, profits[i] + memoized_rot_cut(profits, n - i));
  }

  r[n] = q;
  return q;
}

void run() {
  int n = 10;

  vector<int> profits(n+1);

  profits[1] = 1;
  profits[2] = 5;
  profits[3] = 8;
  profits[4] = 9;
  profits[5] = 10;
  profits[6] = 17;
  profits[7] = 17;
  profits[8] = 20;
  profits[9] = 24;
  profits[10] = 30;

  debug() << memoized_rot_cut(profits, 4);
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

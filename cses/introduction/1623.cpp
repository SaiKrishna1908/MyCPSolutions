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

long to_be_or_not_to_be(vector<int> &input,long lsum, long rsum, int i) {  
  if (i >= input.size()) {
    return abs(rsum-lsum);
  }
  long l = to_be_or_not_to_be(input, lsum+input[i], rsum , i+1);
  long r = to_be_or_not_to_be(input, lsum, rsum+input[i], i+1);
  
  return min(l, r);
}


void run() {
  int n;
  cin>>n;

  vector<int> input(n);

  for(int i=0;i<n;i++) {
    cin>>input[i];
  }

  int min =  to_be_or_not_to_be(input, 0, 0, 0);  

  cout<<min<<endl;
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  // auto start = high_resolution_clock::now();
  
  run();
  
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

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

string swap(string s, int l, int r) {
  char temp = s[l];
  s[l] = s[r];
  s[r] = temp;

  return s;
}

void run() {
  string s;
  cin>>s;

  if (s.length() == 1) {
    cout<<1<<endl;
    cout<<s<<endl;
    return;
  }

  set<string> per;

  stack<string> st;

  st.push(s);

  while(!st.empty()) {
    string currents = st.top();
    st.pop();
    for(int i=0;i<currents.length();i++) {
      for(int j=i+1;j<currents.length();j++) {
        string updated = swap(currents, i, j);
        if (per.find(updated) == per.end()) {
          st.push(updated);
        }
        per.insert(updated);
      }
    }
  }  

  vector<string> per_vec(per.begin(), per.end());
  cout<<per_vec.size()<<endl;

  for(int i=0;i<per_vec.size();i++) {
    cout<<per_vec[i]<<endl;
  }
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

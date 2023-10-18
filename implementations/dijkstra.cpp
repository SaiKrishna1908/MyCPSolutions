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

/*
  uses matrix representation
*/
void dijstras(vector<vector<pair<int,int>>> &vec, vector<int> &dist, vector<int> &parent, int source) {
  assert(source >=0 && source <= vec.size());
  vector<bool> visited(vec.size());

  int n = vec.size();

  fill(all(dist), INT_MAX);

  visited[source] = 0;

  int curr_vertex = source;

  for(int i=0;i<n;i++) {
    int v = -1;

    for(int j=0;j<n;j++) {
      if (!visited[j] && (v == -1 || dist[j] < dist[v])) {
        v = j;
      }
    }

    if (dist[v] == INF) {
      break;
    }

    visited[v] = true;

    for(auto neighbour : vec[v]) {
      int to = neighbour.first;
      int len = neighbour.second;

      if (dist[v] + len < dist[to]) {
        dist[to] = dist[v] + len;        
      }
    }
  }
}

void run() {
  int n;
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

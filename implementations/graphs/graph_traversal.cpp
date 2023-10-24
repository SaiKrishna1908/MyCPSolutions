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

void print_bfs(vector<vector<int>> &adj_list, int source) {
  auto que = queue<int>();
  que.push(source);

  vector<bool> visited(adj_list.size());

  vector<int> distance(adj_list.size(), INT_MAX);

  distance[source] = 0;

  while(!que.empty()) {
    int current_vertex = que.front();
    que.pop();
    if (visited[current_vertex]) {
      continue;
    } else {
      int current_distance = distance[current_vertex] + 1;
      debug() << current_vertex;      
      visited[current_vertex] = true;
      for(auto neighbour : adj_list[current_vertex])  {
        distance[neighbour] = min(distance[neighbour], current_distance);
        que.push(neighbour);
      }  
    }
  }

  debug() << distance;
}

void print_dfs(vector<vector<int>> &adj_list, int source) {
  auto stk = stack<int>();

  vector<bool> visited(adj_list.size(), false);

  stk.push(source);

  while(!stk.empty()) {
    int current_vertex = stk.top();
    stk.pop();

    if (visited[current_vertex]) {
      continue;
    } else {
      cout<<current_vertex<<"->";
      visited[current_vertex] = true;
      for(auto neighbour : adj_list[current_vertex]) {
        stk.push(neighbour);
      }
    }    
  }
}


void run() {  
  int n = 7;

  vector<vector<int>> adj_list(7);

  adj_list[1].push_back(2);
  adj_list[1].push_back(3);
  adj_list[2].push_back(1);
  adj_list[2].push_back(4);
  adj_list[3].push_back(1);
  adj_list[3].push_back(4);
  adj_list[3].push_back(5);
  adj_list[4].push_back(2);
  adj_list[4].push_back(3);
  adj_list[4].push_back(5);
  adj_list[4].push_back(6);
  adj_list[5].push_back(3);
  adj_list[5].push_back(4);
  adj_list[5].push_back(6);
  adj_list[6].push_back(4);
  adj_list[6].push_back(5);
  
  print_dfs(adj_list, 1);
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

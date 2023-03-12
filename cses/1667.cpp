#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
using namespace std::chrono;
 
#define ll long long
#define all(v) v.begin(), v.end()
 
#define MAXN 100007
 
vector<vector<int>> g(MAXN);
 
bool isVisited[MAXN];
 
deque<int> dq;
 
// parent vertex of g[i][j]
int parent[MAXN];
 
void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}
 
void bfs(int n) {
  while(!dq.empty()) {
    
    
    int current_vertex = dq.front();    


    isVisited[current_vertex] = true;
    dq.pop_front();

    if (current_vertex == n) {    
      return;
    }    
 
    for(int i=0;i<g[current_vertex].size();i++) {
      if (!isVisited[g[current_vertex][i]]) {
        dq.push_back(g[current_vertex][i]);
        parent[g[current_vertex][i]] = current_vertex;
        isVisited[g[current_vertex][i]] = true;
      }      
    }    
  }
}
 
 
void run() {
  int n,m;
  cin>>n>>m;
 
  for(int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
 
    g[a].push_back(b);    
    g[b].push_back(a);    
  }
 
  parent[1] = -1;
  dq.push_back(1);
  bfs(n);
 
  if (!isVisited[n]) {
    cout<<"IMPOSSIBLE"<<endl;
  } else {
 
    vector<int> route;
    int current_v = n;
    while(current_v >= 1) {
      route.push_back(current_v);
      current_v = parent[current_v];
    }
 
    cout<<route.size()<<endl;
    for(auto it = route.rbegin(); it != route.rend(); it++) {
      cout<<(*it)<<" ";
    } 
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
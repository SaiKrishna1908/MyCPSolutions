#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
using namespace std::chrono;
 
#define ll long long
#define all(v) v.begin(), v.end()
 
#define MAXN 100007
 
bool isVisited[MAXN];
vector<vector<int>> graph(MAXN);
 
void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}
 
 
void dfs(int vertex) {
  isVisited[vertex] = true;
 
  for(int i=0;i<graph[vertex].size();i++) {
    if(!isVisited[graph[vertex][i]]) {
      dfs(graph[vertex][i]);
    }
  }
}
 
void run() {
  int n,m;
  cin>>n;
  cin>>m;  
  
 
  for(int i=0;i<m;i++) {
    int a,b;
    cin>>a>>b;
 
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
 
  int count = 0;
  
  vector<int> parents;
 
  for(int i=1;i<=n;i++) {
    if (!isVisited[i]) {
      parents.push_back(i);
      count++;
      dfs(i);
    }
  }
 
  cout<<count-1<<endl;
 
  for(int i=1;i<parents.size();i++) {
    cout<<parents[i]<<" "<<parents[i-1]<<endl;
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
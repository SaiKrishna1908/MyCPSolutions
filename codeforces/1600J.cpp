#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

int a[1002][1002]; 
bool visited[1002][1002];


void init() {

  for(int i=0;i<1002;i++) {

    for(int j=0;j<1002;j++) {
      visited[i][j] = false;
    }
  }
}

int dfs_count_rooms(int n, int m, int i, int j) {

  if(visited[i][j]) {
    return 0;
  }

  visited[i][j] = true;

  int count =1;

  if(i+1 < n && !((a[i][j]>>1)&1 | (a[i+1][j]>>3)&1)) {
    count+=dfs_count_rooms(n,m,i+1,j);  
  }

  if(i-1>=0 && !((a[i][j]>>3)&1 | (a[i-1][j]&1>>1)&1)) {
    count+=dfs_count_rooms(n,m,i-1,j);
  }
  // For down of current element current>>1&1 | currnent+
  if(j-1<m && !(a[i][j]&1 | (a[i][j-1]>>2)&1)) {
    count+=dfs_count_rooms(n,m,i,j-1);
  }
        // For top
  if(j+1>=0 && !((a[i][j]>>2)&1 | (a[i][j+1])&1)){
    count+=dfs_count_rooms(n,m,i,j+1);
  }

  return count;
}

void run() {
  
  int n,m;

  cin>>n>>m;

  init();


  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin>>a[i][j];
    }
  }


  vector<int> res;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {

      if (!visited[i][j]) {
        int no_of_rooms = dfs_count_rooms(n,m,i,j);
        res.push_back(no_of_rooms);
      }
    }
  }

  sort(res.begin(),res.end());

  for(int i=res.size()-1 ;i>=0;i--) {
    cout<<res[i]<<" ";
  }
}

int main() {

// cin.tie(0);
// cin.sync_with_stdio(false);
    

//  auto start = high_resolution_clock::now();
  
  run();
  
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

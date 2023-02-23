#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAX 1000

bool isVisited[MAX][MAX];


// wall if input[i][j] = 0
// floor if input[i][j] = 1  
  

int input[MAX][MAX];

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, -1, 0, 1};

int n, m;

bool isValid(int x, int y) {
  if (x >= n) return false;
  if (y >= m) return false;
  if (x < 0 || y < 0) return false;
  
  return input[x][y];
}

void dfs(int x, int y) {
  isVisited[x][y] = 1;
  for(int i=0;i<4;i++) {
    
      int newX = dx[i] + x;
      int newY = dy[i] + y; 

      if (isValid(newX, newY) && !isVisited[newX][newY]) {
        dfs(newX, newY);        
      
    }
  }
}

void run() {  



  cin>>n>>m;

  int connected_components = 0;

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      char c;
      cin>>c;

      input[i][j] = (c == '.');
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if (input[i][j] && !isVisited[i][j]) {
        dfs(i,j);
        connected_components++;
      }
    }
  }

  cout<<connected_components<<endl;  
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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

void run() {
  int t;

  cin>>t;

  while(t-->0) {
    int n,k,ix,iy;

    cin>>n>>k>>ix>>iy;    

    
    char map[n+1][n+1];

    int x_start = 1;
    int y_start = 1;

    while(x_start <= n-k+1 && y_start<=n-k+1) {
      for(int i=x_start;i<=x_start*k && i <=n;i++) {
        for(int j=y_start;j<=y_start*k && j <=n;j++) {
          // This is a diagonal point, shift this           
          if ((i+j)%k == (ix+iy) %k) {
            map[i][j]= 'X';
          } else {
            map[i][j] = '.';
          }
        }        
      }
      if (y_start == n-k+1) {
        x_start+=k;
        y_start = 1;
      } else {
        y_start += k;     
      }            
    }      
    
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=n;j++) {
        cout<<map[i][j];
      }
      cout<<endl;
    }    
  }  
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

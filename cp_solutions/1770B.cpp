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
    int n,k;

    cin>>n>>k;

    int left_pt = 1;
    int right_pt = n;

    vector<int> result(n+1);

    for(int i=1;i<=n;i++) {
      if (i%2) {
        result[i] = right_pt;
        right_pt--;
      } else {
        result[i] = left_pt;
        left_pt++;
      }      
    }
    
    
    for(int i=1;i<=n;i++) {
      
      cout<<result[i]<<" ";
    }
    cout<<endl;
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

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

    vector<int> a(n+1);

    bool is_sorted = true;

    for(int i=1;i<=n;i++) {      
      cin>>a[i];
      if (a[i] != i) {
        is_sorted = false; 
      }
    }

    if (is_sorted) {
      cout<<0<<endl;
      continue;
    }

    int current_num = 1;

    for(int i=1;i<=n;i++) {
      if(a[i] == current_num) {
        current_num++;
      }
    }
    
    cout<<(n-current_num+k)/k<<endl;
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

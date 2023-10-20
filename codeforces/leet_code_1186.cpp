#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
  int  a[] = {1,-2,0,3};

  int n = 4;

  // Deletion happens
  int suf_del = 0;

  // No Deletion happened
  int suf_no_del = a[0];

  int max_so_far = a[0];

  for(int i=1;i<n;i++) {
    
    // suf deleetion -> max (deletetion happened before, delete current element)
    suf_del = max(suf_del+a[i], suf_no_del);

    // suf_no_del -> max(no prior deletion + a[i], a[i])
    suf_no_del = max(suf_no_del+a[i], a[i]);

    max_so_far = max({max_so_far, suf_no_del, suf_del});
  }

  cout<<max_so_far<<endl;
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

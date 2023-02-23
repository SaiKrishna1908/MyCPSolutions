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
  int n;
  cin>>n;

  vector<int> a(n);

  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  sort(a.begin(), a.end());

  ll res = 1;

  for(int i=0;i<n;i++) {
    if (a[i] <= res) {
      res+=a[i];
    } else {
      break;
    }
  }

  cout<<res<<endl;
  
}


int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
  return 0;
}

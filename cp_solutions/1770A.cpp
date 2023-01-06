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
    int n,m;

    cin>>n>>m;

    vector<int> a(n);
    vector<int> b(m);
 

    for(int i=0;i<n;i++) {
      cin>>a[i];
    }

    for(int i=0;i<m;i++) {
      cin>>b[i];      
    }        

    for(int i = 0;i<b.size();i++) {
      sort(a.begin(), a.end());
      a[0] = b[i];
    }

    ll sum =0;

    for(auto el : a) {
      sum = sum + el;
    }

    cout<<sum<<endl;       
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

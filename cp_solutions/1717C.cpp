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
    int n;

    cin>>n;

    int a[n];
    int b[n];


    int carry[n];    

    vector<pair<int, int>> v(n);

    for(int i=0;i<n;i++) {
      cin>>a[i];
    }

    for(int i=0;i<n;i++) {
      cin>>b[i];
    }

    bool is_possible = true;

    for(int i=0;i<n;i++) {

      if (a[i] > b[i]) {
        is_possible = false;
        break;
      }
      else if (a[i] < b[i] && !(b[i] <= (i == n-1 ? b[0] : b[i+1]) + 1)) {
        is_possible = false;
      }
    }
    
    if (is_possible ) {
      cout<<"Yes"<<endl;
    } else {
      cout<<"NO"<<endl;
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

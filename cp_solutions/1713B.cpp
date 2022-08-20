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

    int arr[n];    

    for(int i=0;i<n;i++) {
      cin>>arr[i];                  
    }    

    int pref_length=0;
    int suf_length=0;

    int i=1;

    for(;i<=n-1;i++) {
      if (arr[i] < arr[i-1]) {
        break;
      }
      pref_length++;
    }

    i--;

    for(;i<n-1;i++) {
      if (arr[i] < arr[i+1]) {
        break;
      }
      suf_length++;
    }

    if (pref_length + suf_length + 1 == n) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
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

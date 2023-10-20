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
  ll n, n_score;
  cin>>n>>n_score;

  vector<ll> a(n);

  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  sort(a.begin(), a.end());


  int count = 0, start = 0, end = n-1;

  while(a[end] > n_score && end >= 0) {
    end--;
    count++;
  }
  
  while(start < end) {
    ll sum = 2 * a[end];
    while(sum <= n_score && start < end) {
      start++;
      sum += a[end];
    }

    if (start < end) {
      count++;
    }

    start++;    
    end--;
  }

  cout<<count<<endl;
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

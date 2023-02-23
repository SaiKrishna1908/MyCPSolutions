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

  vector<ll> a(n);

  bool is_array_negative = true;

  for(int i=0;i<n;i++) {
    cin>>a[i];

    if (is_array_negative && a[i] > 0) {
      is_array_negative = false;
    }
  }

  ll run_sum = 0;
  ll max_sum = 0;

  if (is_array_negative) {
    sort(a.rbegin(), a.rend());

    cout<<a[0]<<endl;
    return;
  }


  for(int i=0;i<n;i++) {
    run_sum = max(run_sum+a[i], a[i]);

    if (run_sum < 0) {
      run_sum = 0;
    }

    if (run_sum > max_sum) {
      max_sum = run_sum;
    }
  }

  cout<<max_sum<<endl;
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

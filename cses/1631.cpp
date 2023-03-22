#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7


void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int n;
  cin>>n;

  vector<ll> val(n+1);

  vector<ll> prefix(n+1);  

  for(int i=1;i<=n;i++) {
    cin>>val[i];
  }

  sort(val.begin(), val.end());

  for(int i=1;i<=n;i++) {
    prefix[i] = prefix[i-1] + val[i];    
  }

  ll time_needed = INF;

  bool to_multiply = false;

  for(int i=1;i<=n;i++) {
    ll current_element = prefix[i] - prefix[i-1];

    if (current_element > prefix[i-1])  {
      time_needed = current_element;
      to_multiply = true;
    } else {
      time_needed = prefix[i];
      to_multiply = false;
    }
  }

  cout<<(time_needed * (to_multiply ? 2 : 1))<<endl;
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

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

    vector<int> v(n);

    for(int i=0;i<n;i++) {
      cin>>v[i];
    }

    sort(v.begin(), v.end());

    ll ans1 = v[n-1];

    for(int i=0;i<n-1;i++) {
      ans1 = ans1 * v[i];
    }

    ans1 += (n-1);

    ll ans2 = v[0];

    sort(v.rbegin(), v.rend());

    for(int i=0;i<n-1;i++) {
      ans2 *= v[i];
    }

    ans2 += (n-1);

    cout<<(max(ans1, ans2) * 2022ll) <<endl;

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

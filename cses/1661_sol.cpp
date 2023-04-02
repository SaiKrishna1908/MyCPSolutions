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
  int n,x;

  cin>>n>>x;

  vector<int> v(n+1);
  vector<int> p(n+1);

  for(int i=1;i<=n;i++) {
    cin>>v[i];    
  }

  map<ll, int> m;

  m[0]++;

  ll sum = 0;
  ll count = 0;

  for(int i=1;i<=n;i++) {
    sum += v[i];
    count += m[sum-x];
    m[sum]++;
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

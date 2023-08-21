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
  int n,q;

  cin>>n>>q;

  vector<ll> prefix_sums(n+1);



  for(int i=1;i<=n;i++) {

    ll input;
    cin>>input;
    prefix_sums[i] =  prefix_sums[i-1] + input;
  }

  for(int i=0;i<q;i++) {
    int a,b;
    cin>>a>>b;

    cout<<(prefix_sums[b] - prefix_sums[a-1])<<endl;
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

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

  vector<int> v;

  v.push_back(0);

  for(int i=1;i<n;i++) {
    int x;
    cin>>x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  

  for(int i=1;i<=n;i++) {
    if (v[i] != i) {
      cout << i;
      return;
    }
  }

  return;
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

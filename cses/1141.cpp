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

  vector<int> a(n);

  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  map<int,int> pos_map;

  int start_index=0;

  int max_count = 0;


  for(int i=0;i<n;i++) {

    // already present make start_index = pos_map[a[i]].second
    if (pos_map.count(a[i]) && i < n) {
      start_index = max(start_index, pos_map[a[i]]+1);      
    }

    pos_map[a[i]] = i;    

    max_count = max(max_count, i - start_index + 1);
  }
  

  cout<<max(1,max_count)<<endl;
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

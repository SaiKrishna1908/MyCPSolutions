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

  vector<pair<int ,int>> events;

  for(int i=0;i<n;i++) {
    int st, et;
    cin>>st>>et;
    events.push_back(make_pair(st, et));    
  }


  sort(events.begin(), events.end(), [](pair<int,int> i, pair<int,int> j) {
     return i.second < j.second;
  });

  int prev_et = -1;
  int count = 0;

  for(int i=0;i<n;i++) {
    if (events[i].first >= prev_et) {
      count++;
      prev_et = events[i].second;
    }
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

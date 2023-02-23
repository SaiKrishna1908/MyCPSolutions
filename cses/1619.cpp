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
  vector<pair<int,int>> events;

  for(int i=0;i<n;i++) {

    int a,b;
    cin>>a>>b;
    events.push_back(make_pair(a, 1));
    events.push_back(make_pair(b, -1));
  }


  sort(events.begin(), events.end(), [](pair<int,int> i , pair<int, int> j) {
    return i.first < j.first;
  });

  
  ll max_count = 0;
  ll count = 0;

  for(int i=0;i<events.size();i++) {
    count += events[i].second;
    max_count = max (max_count, count);
  }

  cout<<max_count<<endl;
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

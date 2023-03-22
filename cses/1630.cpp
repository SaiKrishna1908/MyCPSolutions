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

  vector<pair<ll,ll>> pr;

  for(int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;

    pr.push_back(make_pair(a,b));
  }

  sort(pr.begin(), pr.end(), [](pair<int,int> a, pair<int,int> b) {

    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });

  ll sum = 0;
  ll current_time=0;

  for(int i=0;i<n;i++) {
    current_time = current_time + pr[i].first;
    sum = sum + (pr[i].second - current_time);        
  }

  cout<<sum<<endl;
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

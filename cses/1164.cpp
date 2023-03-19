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

  vector<pair<int,pair<int,int>>> pr;

  for(int i=0;i<n;i++) {
    int a,b;
    cin>>a>>b;
    pr.push_back(make_pair(i, make_pair(a,b)));    
  }

  sort(pr.begin(), pr.end(), [] (pair<int,pair<int,int>> a, pair<int,pair<int, int>> b) {
    return a.second.first < b.second.first;
  });

  // value and room_number
  priority_queue<pair<int,int>> pq;

  vector<int> ans(n);


  int rooms = 0;
  int last_room = 0;  
  
  for(int i=0;i<pr.size();i++) {
    if (pq.empty()) {
      last_room++;
      pq.push(make_pair(-pr[i].second.second, last_room));
      ans[pr[i].first] = last_room;
    } else {
      auto min_elem = pq.top();

      if (-pr[i].second.first < min_elem.first) {
        pq.pop();
        pq.push(make_pair(-pr[i].second.second, min_elem.second));
        ans[pr[i].first] = min_elem.second;
      } else {
        last_room++;
        pq.push(make_pair(-pr[i].second.second, last_room));
        ans[pr[i].first] = last_room;
      }
    }
    
    rooms = max(rooms, (int) pq.size());
  }

  cout<<rooms<<endl;

  print_vec(ans);
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

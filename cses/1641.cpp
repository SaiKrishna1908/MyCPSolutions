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

  vector<pair<int,int>> v(n);

  for(int i=0;i<n;i++) {
    int input;
    cin>>input;
    v[i] = make_pair(input, i);
  }

  sort(v.begin(), v.end());

  pair<int, pair<int,int>> ans;

  bool is_possible = false;

  for(int i=0;i<n-2;i++) {
    int target = x - v[i].first;

    int low = i+1;
    int high = n-1;

    while(low < high) {      
      int sum = v[low].first + v[high].first;

      if (sum > target)  {
        high--;
      } else if (sum < target) {
        low++;
      } else {
        ans = make_pair(v[i].second, make_pair(v[low].second, v[high].second));
        is_possible = true;
        break;
      }
    }

    if (is_possible) {
      break;
    }    
  }

  if (is_possible) {
    cout<<(ans.first+1)<<" "<<(ans.second.first+1)<<" "<<(ans.second.second+1)<<endl;
  } else {
    cout<<"IMPOSSIBLE"<<endl;
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

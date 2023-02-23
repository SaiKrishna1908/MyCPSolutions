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
  int n, s;
  cin>>n>>s;

  vector<pair<int,int>> a(n);

  for(int i=0;i<n;i++) {
    int num;
    cin>>num;
    a[i] = make_pair(num, i+1);
  }

  sort(a.begin(), a.end());

  int low = 0;
  int high = n-1;

  while(low <= high) {
    int sum = a[low].first + a[high].first;

    if (sum > s) {
      high--;
    } else if (sum < s) {
      low++;
    } else {
      break;
    }
  }

  if (low >= high) {
    cout<<"IMPOSSIBLE";
  } else {
    cout<<a[low].second<<" "<<a[high].second<<endl;
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

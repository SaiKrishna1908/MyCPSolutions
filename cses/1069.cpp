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
  string s;

  cin>>s;

  int n = s.length();

  int ans = s.length() == 1 ? 1 : -1;

  int temp = 1;

  for(int i=1;i<n;i++) {
    if(s[i] == s[i-1]) {
      temp++;      
    } else {
      temp = 1;
    }
    ans = max(ans, temp);
  }

  cout<<ans;
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

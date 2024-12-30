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
  int t;
  cin>>t;

  while(t-->0) {
    int a,b;
    cin>>a>>b;

    ll sum = a+b;

    if ((a ==0 && b != 0) || (a != 0 && b == 0)) {
      cout<<"NO"<<endl;
      continue;
    }

    ll max_tries = max(a,b)/2;

    if ((sum)%3 == 0 && max_tries <= min(a,b)) {
      cout<<"YES"<<endl;
      continue;
    } 

    cout<<"NO"<<endl;
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

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
    int a,b,diff;
    cin>>a>>b>>diff;

    if (diff == 0) {
        if (a == b) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        continue;
    }

    ll lower_bound = min(a, b);

    ll limit = lower_bound * ( lower_bound + diff );

    ll max_value = max(a, b);

    if (max_value <= limit) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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

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
  int t;

  cin>>t;

  while(t--> 0 ) {
    int n,m;
    cin>>n>>m;

    vector<ll> a(m);

    for(int i=0;i<m;i++) {
      cin>>a[i];
    }


    sort(a.begin(), a.end());

    vector<ll> diff(m);


    for(int i=0;i<m-1;i++) {
      diff[i] = a[i+1] - a[i] - 2;                  
    }

    diff[m-1] = ((n - a[m-1]) + (a[0] - 1)) - 1;

    sort(diff.begin(), diff.end(), greater<int>());

    int count = 0;
    for(int i=0;i<m;i++) {
        if ((diff[i] - 4 * i < 0)) {
          continue;
        }
        count += max(1ll,diff[i] - 4 * i);
    }

    cout<<(n-count)<<endl;    
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

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
    int n,x;
    cin>>n>>x;

    vector<int> v(n);
    
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int count = 0;

    // Greedy won't work
    int low = 0;
    int high = n-1;

    int pairs=0;

    while(low < high) {
      int lowe = v[low];
      int highe = v[high];

      int sum = lowe+highe;

      if (sum > x) {
        high--;
      } else {
        low++;
        high--;
        pairs++;
      }
    }

    int ans = (n - (2 * pairs)) + pairs;

    cout<<ans<<endl;
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

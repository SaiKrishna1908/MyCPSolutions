#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int t;

  cin>>t;

  while(t-->0) {
    int n,k;

    cin>>n>>k;

    long a[n];
    int b[n-1];

    for(int i=0;i<n;i++) {
      cin>>a[i];
    }

    /*
        b[0] -> a[0], a[1] -> 1
        b[1] -> a[1], a[2] -> 1
        b[2] -> a[2], a[3] -> 1
    */
    
    for(int i=0;i<n-1;i++) {
      if (a[i] < (2 * a[i+1])) {
        b[i] = 1;
      } else {
        b[i] = 0;
      }
    }

    int prefix_sum[n-1];

    prefix_sum[0] = b[0];

    /*
      
      prefix_sum[0] -> 1
      prefix_sum[1] -> 2
      prefix_sum[2] -> 3

    */

    for(int i=1;i<n-1;i++) {
      prefix_sum[i] = prefix_sum[i-1] + b[i];
    }

    int count = 0;
    
    for(int i=0;i<n-k;i++) {
      int start_index = i;
      int end_index = i + k - 1;

      int sum = prefix_sum[end_index] - (start_index ? prefix_sum[start_index-1] : 0);
      if (sum == k) {
        count++;
      }      
    }

    cout<<count<<endl;
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

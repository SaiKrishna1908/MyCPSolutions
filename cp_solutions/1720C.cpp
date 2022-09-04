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

  while(t-->0) {
    int n,m;

    cin>>n>>m;

    string s;

    int a[n][m];

    int sum = 0;

    for(int i=0;i<n;i++) {
      cin >> s;

      for(int j=0;j<m;j++) {
        a[i][j] = s[j] - '0';
        sum+=a[i][j];
      }            
    }

    // Find the maximum number of zeros possible in a 2X2 square
    int max_zeros = INT_MIN;

    for(int i=0;i<n-1;i++) {
      for(int j=0;j<m-1;j++) {
        int count = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
        max_zeros = max(max_zeros, 4 - count);        
      }
    }

    if (max_zeros >= 2) {
      cout<<sum<<endl;
    } else if (max_zeros == 1) {
      cout<<sum-1<<endl;
    } else {
      cout<<sum-2<<endl;
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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  int n;
  cin>>n;

  int a[2][n+1];

  a[0][0] = -1;
  a[1][0] = -1; 

  int min = INT_MAX;

  for(int i=0;i<2;i++) {
    for(int j=1;j<=n;j++) {

      if (j==1) {
        cin>>a[i][j];
      } else {
          
        int temp;
        cin>>temp;
        a[i][j] = a[i][j-1] + temp;
      }
    }
  }

  // for(int i=0;i<2;i++) {
  //   for(int j=1;j<=n;j++) {
  //     cout<<a[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  for(int i=1;i<=n;i++) {
    int temp_min = std::max(a[0][n] - a[0][i], a[1][i-1]);

    if(temp_min < min) {
      min = temp_min;
    }
  }

  if(min == INT_MAX) {
    cout<<0<<endl;
    return;
  }
  cout<<min<<endl;


  
}

int main() {

    cin.tie(0);
  cin.sync_with_stdio(false);
auto start = high_resolution_clock::now();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  int t;
  cin>>t;

  while(t-->0) {
    run();
  }

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

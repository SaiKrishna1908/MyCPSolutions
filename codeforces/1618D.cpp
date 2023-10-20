#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int t;

  cin>>t;

  while (t-->0) {
    int n,k;

    cin>>n>>k;

    vector<int> arr(n+1);

    for(int i=1;i<=n;i++) {
      cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int sum=0;

    for(int i=0;i<k;i++) {
      int res = floor(arr[n-i-k]/arr[n-i]);
      sum+=res;      
    }

    for(int i=1;i<=n-2*k;i++)    {
      sum += arr[i];
    }

    cout<<sum<<endl;    
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

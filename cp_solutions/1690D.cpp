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

    // B-0, W-1

    vector<int> buck(2);

    vector<char> arr(n);

    for(int i=0;i<n;i++) {
      cin>>arr[i];
    }

    for(int i=0;i<k;i++) {
      if (arr[i] == 'B') {
	buck[0]++;
      }else {
	buck[1]++;
      }
    }

    int min = buck[1];
    
    for(int i=k;i<n;i++) {
      if (arr[i-k] == 'B') {
	buck[0]--;	
      }  else if (arr[i-k] == 'W') {
	buck[1]--;
      }
      
      if (arr[i] == 'B') {
	buck[0]++;
      } else if (arr[i] == 'W') {
	buck[1]++;
      }

      if (min > buck[1]) {
	min = buck[1];
      }
    }

    cout<<min<<endl;
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

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
    int n;
    cin>>n;

    int x[n];
    int y[n];

    // Money they want to spend
    for(int i=0;i<n;i++) {
      cin>>x[i];  
    }

    // Money they have in pockets
    for(int i=0;i<n;i++) {
     cin>>y[i]; 
    }

    vector<pair<ll,int>> diffs(n);

    for(int i=0;i<n;i++) {
      diffs[i].first = y[i] - x[i];
      diffs[i].second = i;
    }


    sort(diffs.begin(), diffs.end());
    reverse(diffs.begin(), diffs.end());
        
    int end = n-1;
    int groups = 0;    

    for(int i=0;i<n;i++) {
      while(end > i && diffs[i].first + diffs[end].first < 0) {
        end--;
      }       
      if (end <= i) break;
      groups++;
      end--;
    }
    cout<<groups<<endl;
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

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

    vector<int> arr(n+1);
    
    int minimal_pile_index = INT_MAX ;
    int minimal_pile = INT_MAX;

    for(int i=1;i<=n;i++) {
      
      cin>>arr[i];

      if (minimal_pile> arr[i]) {
        minimal_pile = arr[i];
        minimal_pile_index = i;                    
      } 
    }

    int chance = 0;

    if (n%2) {
      cout<<"Mike"<<endl;
      continue;
    }    

    if ((minimal_pile_index%2) == 0) {
      cout<<"Mike"<<endl;
    }

    else if (minimal_pile_index % 2) {
      cout<<"Joe"<<endl;
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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int n;

  cin>>n;

  int height = 1;

  vector<int> day(n);

  bool is_watered = false;

  for(int i=0;i<n;i++) {  
    cin>>day[i];    
  }


  day[0] ==1 ? ++height : height;

  for(int i=1;i<n;i++) {

    if(day[i] == 0 && day[i-1] ==0) {
      height = -1;
      break;
    }

    if (day[i] == 1) {
      height++;
    }

    if (day[i] == 1 && day[i-1] == 1) {
      height+=4;
    }    
  }

  cout<<height<<endl;
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    
  auto start = high_resolution_clock::now();

  int t;

  cin>>t;

  while(t-->0) {
    run();
  }
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

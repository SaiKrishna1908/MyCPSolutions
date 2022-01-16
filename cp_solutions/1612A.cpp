#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  int a,b;
  cin>>a>>b;

  if ((a+b)%2 != 0) {
    cout<<"-1 -1"<<endl;
    return;
  }

  for(int i=0;i<=(a+b)/2;i++) {
    int y = (a+b)/2 - i;

    int dis = abs(a-i) + abs(b-y);

    if(dis == (a+b)/2) {
      cout<<i<<" "<<y<<endl;
      return;
    }
  }

  cout<<"-1 -1"<<endl;
  
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

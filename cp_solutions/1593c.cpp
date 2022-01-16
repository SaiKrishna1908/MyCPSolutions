#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
    
  int n,k;

  cin>>n>>k;

  vector<int> pos(k);

  for(int i=0;i<k;i++) {
    cin>>pos[i];

    pos[i] = n - pos[i];
  }


  sort(all(pos));

  for(int i=1;i<k;i++) {

    pos[i] = pos[i] + pos[i-1];

    if(pos[i] >= n) {
      cout<<i<<endl;
      return;
    }

    
  }

  cout<<k<<endl;

}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  // auto start = high_resolution_clock::now();

  int t;
  cin>>t;

  while(t-->0) {
    run();
  }
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

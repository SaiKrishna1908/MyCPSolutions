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
    int n;
    cin>>n;

    vector<int> a(n + 1);

    for(int i=1;i<=n;i++) {
      cin>>a[i];
    }

    if(n%2) {
      cout<<"NO"<<endl;
      continue;
    }

    int m = n/2;

    bool is_possible = true;    
    sort(a.begin(), a.end());

    for(int i=2;i<=m;i++) {
      if ( a[i] == a[m+i-1] ) {
        is_possible = false;
      }
    }

    if(!is_possible) {
      cout<<"NO"<<endl;
      continue;
    }

    vector<int> sol(n+1);

    for(int i=0;i<m;i++) {
      sol[2*i+1] = a[i+1];
      // if (i > 1) {
      //   sol[i*2] = a[i+1];
      // } else {
      //   sol[i] = a[i];
      // }      
    }

    for(int i=1;i<=m;i++) {
      sol[2*i] = a[m+i];
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) {
      cout <<sol[i]<<" ";
    }
    cout<<endl;
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

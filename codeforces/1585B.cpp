#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

    int n;
    int count=0;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++) {        
        cin>>a[i];
    }

    int max = a[n-1];


    for(int i=n-1;i>=0;i--) {
        if(a[i] > max) {
            max = a[i];
            count++;
        }
    }

    cout<<count<<endl;
  
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

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

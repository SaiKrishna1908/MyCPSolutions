#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  ll n,k;
  cin>>n>>k;

  ll count = 1;
  ll loop = 0;

  if(n==1 and k==1) {
    cout<<0<<endl;
    return;
  } else {

    while(count<=k){

      count += min(k, count);
      loop++; 

    }

    // cout<<"loop "<<loop<<" ";
    loop += ((n-count)/k) + ((n-count) % k > 0) ;

  }

  // if(count < n) {

  //   if ( k > (n-count) )
  //     loop += k%(n-count);
  //   else if ((n-count) > k) 
  //     loop +=  (n-count) % k;
  // }

  cout<<loop<<endl;
  return;
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

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define length(a) sizeof(a)/sizeof(a[0])

// Take a sorted in desc order
// ll fs(ll n, int a[]) {


//   ll temp = n;

//   ll count = 0;

//   for(int i=0;i<=(sizeof(a)/sizeof(a[0]));i++) {
//     count=count+(temp/a[i]);
//     temp%=a[i];
//   }

//   return count;
// }

void run() {
  
  int n,k;
  cin>>n>>k;

  ll a[n];

  for(int i=0;i<n;i++) {
    int temp;
    cin>>temp;
    a[i] = pow(10,temp);
  }

  ll count=0;
  k++;

  for(int i=0;i<length(a)-1;i++) {

    if(k <= 0) {
      break;
    }

    int alimit = (a[i+1] - 1)/a[i];

    count += a[i]*min(alimit,k);
    k -= alimit;
  }

  if (k > 0) {
    count+= a[length(a)-1] * k;
  }

  cout<<count<<endl;

}
int main() {

    // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();

  int t;
  cin>>t;

  while(t-->0){
    run();
  }
  
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  int n,k;


  cin>>n>>k;

  vector<int> arr(n+1);


  for(int i=1;i<=n;i++) {

    cin>>arr[i];
  }

  int start = max(1,n-2*k);

  ll ans = -1e12;

  for(int i=start;i<n;i++){
    for(int j=i+1;j<=n;j++) {

      ans = max(ans, 1LL * i * j - 1LL * k * (arr[i] | arr[j]));

    }
  }
  
  cout<<ans<<endl;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t;

  cin>>t;

  while( t-->0 ){ 
     run();
  }
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  run();
}

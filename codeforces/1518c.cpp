#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed;
  cout<<setprecision(10);

  

  int t;

  cin>>t;

  while(t-->0) {

    ll n,l,r;


    cin>>n;
    cin>>l;
    cin>>r;


    vector<int> v(n);

    for(int i=0;i<n;i++) {
      cin>>v[i];
    }




    sort(v.begin(),v.end());

    ll ans =0;


    for(int i=0;i<n;i++) {

      ans  += upper_bound(v.begin(),v.end(), r - v[i]) - v.begin();
      ans -= lower_bound(v.begin(), v.end(), l- v[i] ) - v.begin();

      // check if i = j satisfies the condition
      
      if(v[i]*2 <= r && v[i]*2>=l)
	ans--;

      
    }

    ans /= 2;
    cout<<ans<<"\n";
  }

  return 0;
    
}

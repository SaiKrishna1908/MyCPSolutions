#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n,k,x;

  cin>>n>>k>>x;

  ll temp =k;

  

  vector<ll> v(n);

  for(int i=0;i<n;++i) {
    cin>>v[i];
  }

  if(n==1){
    cout<<1;
    return 0 ;
  }

  sort(v.begin(), v.end());

  
  ll st_groups = 1;

  vector<ll> diffs;


  for(int i=1;i<n;i++) {
    if( v[i] - v[i-1] > x) {

      st_groups++;

      ll diff = v[i] - v[i-1];
      diffs.push_back((diff-1)/x );
    }
  }

  if(st_groups ==1 ){
    
    cout<<st_groups;
    return 0;
  }

  sort(diffs.begin(), diffs.end());
 
  ll idx = 0;

  
  while(k>0 && k>=diffs[idx] && idx<=diffs.size()-1) {


    
    k = k-diffs[idx];
    st_groups--;
    idx++;
  }

  cout<<st_groups;
  
}

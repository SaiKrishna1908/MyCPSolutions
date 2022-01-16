#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


int msb(int n) {

  if(n == 0) {

    return 0;
  }

  n = n/2;
  int msb=0;

  while(n>0) {
    n/=2;
    msb+=1;
  }

  return msb;
}



void run() {

  int a,b;

  cin>>a>>b;

  int ans = a;

  int xr  = 0;  

  for(int i=0;i<a%4;i++) {
    xr ^= a-1-i;
    
  }


  int rq = xr ^ b;


  if(rq == 0) {
    cout<<ans<<endl;
    return;
  }
  else if(rq != a) {
    ans += 1;
  }
  else if(rq  == a) {     
    ans+=2;
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

  while(t-->0)  {
    run();
  }
}

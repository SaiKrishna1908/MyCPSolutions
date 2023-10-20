#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  int n;

  cin>>n;

  int k =0;

  if(n==1){
    cout<<"a"<<endl;
    return;
  }

  if(n%2 == 0) {

    k = n/2;

    for(int i=0;i<k;i++)
      cout<<"a";

    cout<<"b";

    for(int i=1;i<=k-1;i++)
      cout<<"a";
    
  }
  else if (n%2 == 1) {

    k = n/2;

    for(int i=0;i<k;i++) {

      cout<<"a";
    }
    cout<<"bc";

    for(int i=0;i<=k-2;i++) {
      cout<<"a";
    }
  }
  cout<<endl;
  
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t =0;

  cin>>t;

  while(t-->0) {
    run();
  }
}

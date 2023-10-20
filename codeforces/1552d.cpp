#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

  int n;

  cin>>n;

  vector<int> a(n+1);


  int permut = 1;

  for(int i=1;i<=n;i++) {
    cin>>a[i];
    permut *= 3;
  }

  

  for(int k=1;k<permut;k++) {

    int k_it = k;
    int sum = 0;

    for(int i=1;i<=n;i++) {

      // sign = 0 --> zero of this element, sign = 1 --> one of this element, sign = 2 --> minus one of this element

      int sign = k_it%3;

      k_it /= 3;

      if(sign == 2) {
	sign = -1;
      }

      sum += sign * a[i];
      
    }

    if( sum == 0 ) {
      cout<<"YES"<<endl;
      return;
    }          
  }

  cout<<"NO"<<endl;
  return;
  
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t=0;

  cin>>t;

  while (t-->0)  {
    run();
  }
}
  

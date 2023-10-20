#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed;
  cout<<setprecision(10);

  int t;

  cin >> t;

  while( t--> 0 ){

    int n,k;
    cin >>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
      cin>>a[i];

    int idx =0;


    while(idx < n-1 && k>0){

      if(a[idx] ==0){
	idx++;
	continue;
      }
      else {	
	a[idx]--;
	a[n-1]++;
      }
      
      k--;
    }

    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
    cout<<"\n";
  }

}

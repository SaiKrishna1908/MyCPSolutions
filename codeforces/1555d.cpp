#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

#define ll long long

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,m;

  cin>>n>>m;


  char arr[n];

  int aux[n];  
  cin>>arr;

  string permut[] = {"abc","acb","bac", "bca","cab","cba"  };

  

  vector<vector<int>> prefix(6, vector<int>(n+1));

  // for(int i=0;i<6;i++) {

  //   int div = n/3;
  //   int mod = n%3;

  //   for(int j=0;j<div-1;j++) {
  //     permut[i] += permut[i];      
  //   }

  //   permut[i] += permut[i].substr(0,mod);

    
  // }


  for(int i=0;i<6;i++) {

    for(int j=0;j<n;j++) {
      if(arr[j] != permut[i][j%3]) {
	prefix[i][j+1] = prefix[i][j] + 1;
      }
      else {
	prefix[i][j+1] = prefix[i][j];
      }
    }
  }


  // for(int i=0;i<6;i++) {

  //   for(int j=0;j<=n;j++) {

  //     cout<<prefix[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  while (m-->0) {

    int l,r;

    cin>>l>>r;

    int  min = 999999999;
    for(int i=0;i<6;i++) {

      int sum = prefix[i][r] - prefix[i][l-1];

      if(min > sum) {
  	min = sum;
      }
	
    }
    cout<<min<<endl;
  }

  
  
}

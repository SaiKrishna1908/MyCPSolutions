#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


ll MOD = 1000000007;

ll arr[200005][10];


void precalc() {  

  memset (arr, 0, sizeof(arr));

  for(int j=0;j<=9;j++) {
    arr[0][j] = 1;
  }

  for(int i=1;i<200'005;i++) {

    for(int j=0;j<9;j++) {

      arr[i][j] = arr[i-1][j+1] ;
    }

    arr[i][9] = (arr[i-1][1] + arr[i-1][0]) % MOD;
  }
  
}

void run() {			      



  string s;
  cin>>s;

  int m;
  cin>>m;


  ll sum =0;

  for(char c: s) {
    sum  =  (sum + arr[m][c-'0'] )%MOD;
  }

  cout<<sum<<endl;  
}

int main() {

  precalc();

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  int t;

  cin>>t;

  while(t-->0) {
    run();
  }
}

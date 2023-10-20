#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solution(int n,int k, int dir);


int dp[1001][1001][2];

const int mod = 1e9+7;

int n;

void init() {
  

  // Initialize dp to -1
  for(int i=0;i<1001;i++) {
    for(int j=0;j<1001;j++) {

      dp[i][j][0] = -1;
      dp[i][j][1] = -1;
    }
  }      
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  int t;

  cin>>t;

  while(t-->0) {


    int k;

    cin>>n>>k;

    init();

    ll sum = solution(1,k,1)%mod;

    cout<<sum<<endl;
    
  }
}

// K is current particle decay age
ll solution(int curr, int k, int dir ) {


  // Cannot produce any more beams
  if ( k== 1) {

    return 1;
  }

  // First time touching the plane
  else if (dp[curr][k][dir] != -1){

    return dp[curr][k][dir];
  }


  ll sum = 2;

  // travelling straight
  if (dir) {

    if( curr < n) {

      sum = sum + solution(curr+1,k,dir) -1 ;
    }

    
    sum = sum % mod;
    dp[curr][k][dir] = sum;
    

    if ( curr >1 ) {
      sum = sum + solution ( curr-1,k-1 ,1-dir) - 1;
    }

    sum = sum % mod;

    dp[curr][k][dir] = sum;
	
  }

  else {

    if( curr > 1) {

      sum = sum + solution(curr-1,k,dir) -1 ;
    }

    sum = sum % mod;
    dp[curr][k][dir] = sum;
      
    if(curr < n){

      sum = sum + solution(curr+1, k-1, 1-dir) - 1;
      
    }

    sum = sum % mod;
    dp[curr][k][dir] = sum;
  }

  return sum%mod;
  
}

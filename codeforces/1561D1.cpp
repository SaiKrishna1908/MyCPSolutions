#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int mod;

struct BIT {

  
  int n;
  vector<int> bit;

  BIT(int N) {

    n = N;
    bit.assign(N+1,0);
  }

  void update(int i, int v) {
    while( i<=n ) {

      bit[i] = (bit[i] + v)%mod;

      i += i & (-i);
    }
  }

  
    int query(int i) {

      int res = 0;

      while (i>0) {

	res = (res+bit[i])%mod;

	i-=i & (-i);
      }

      return res;
    }
  
};

void run() {


  int num;

  int m;

  cin>>num;
  cin>>m;

  mod = m;

  vector<int> prefix(num+1);
  vector<int> dp(num+1);

  
  dp[1] = 1;

  long sum = 0;

  BIT bit(num);



  for (int i=1;i<=num;i++) {


    if( i != 1) {
      dp[i] = bit.query(i);
    }

    dp[i] = (dp[i] + sum)%mod;
    sum = (dp[i] + sum)%mod;


    for(int j=2;(i*j)<=num;j++) {
      bit.update(i*j, dp[i]);
    }

    for(int j=2; i*j+j <= num;j++) {
      bit.update(i*j + j, -dp[i]);
    }
    
  }

  
  if (dp[num] < 0) {    
    dp[num] = dp[num] + mod;
  }

  cout<<dp[num];
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  run();
}

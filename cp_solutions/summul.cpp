#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

const ll MOD = 1e9+7;


struct matrix {
  ll mat[2][2];
};

matrix I = {
  1,0,0,1
};

matrix A = {
  1,1,1,0
};

matrix multiply(matrix a, matrix b) {
  matrix c;

  for(int i=0;i<2;i++) {
    for(int j=0;j<2;j++) {
      c.mat[i][j] = 0;
      for(int k=0;k<2;k++) {
        c.mat[i][j] = c.mat[i][j] + a.mat[i][k] * b.mat[k][j] % MOD;
      }
      c.mat[i][j] %= MOD;
    }
  }

  return c;
}

matrix power(ll p) {

  matrix ans = I, temp = A;

  while (p) {
    // if odd
    if(p&1) {
      ans = multiply(ans, temp);
    }

    temp = multiply(temp, temp);
    p>>=1;
  }

  return ans;
}


void run()
{

  ll n;

  cin >> n;

  // if (n == 1)
  // {
  //   cout << 0 << endl;
  //   return;
  // }

  // if (n == 2)
  // {
  //   cout << 1 << endl;
  //   return;
  // }

  matrix transformation_matrix = power(n+(n-2));

  
  ll sol = (transformation_matrix.mat[0][0]%MOD  + transformation_matrix.mat[0][1]%MOD);
  cout << ((sol - n) % MOD) << endl;
}

int main()
{

  cin.tie(0);
  cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  int t;
  cin >> t;

  while (t-- > 0)
  {
    run();
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

ll MOD = 1000000007;

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

ll binary_exponentiation(int base, int pow)
{

  if (pow == 1)
  {
    return base * 1;
  }

  ll temp = binary_exponentiation(base, pow / 2);
  if (pow % 2 == 0)
  {
    return (temp % MOD * temp % MOD) % MOD;
  }
  else
  {
    return ((temp % MOD * temp % MOD) * base) % MOD;
  }
}
void run()
{
  int n;

  cin >> n;

  ll ans = binary_exponentiation(2, n);

  cout << (ans % MOD) << endl;
}

int main()
{

  // cin.tie(0);
  // cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  run();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

#define MAXN (int)1e7 + 100

int d[MAXN];
ll s[MAXN];
int ans[MAXN];

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

void print_array_int(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
}

void print_array_ll(ll arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;
}

void run()
{

  fill(d, d + MAXN, -1);

  d[1] = 1;

  for (int i = 2; i * i < MAXN; i++)
  {
    if (d[i] == -1)
    {
      d[i] = i;
      for (int j = i * i; j < MAXN; j += i)
      {
        if (d[j] == -1)
        {
          d[j] = i;
        }
      }
    }
  }

  s[1] = 1;
  /*
      Please note that d[i] contains minimum divisor for a number and it is sure to be a prime number.
      On the other hand s[i] is the divisor function for ith integer
  */
  for (int i = 2; i < MAXN; i++)
  {

    // these are prime numbers
    if (d[i] == -1)
    {
      d[i] = i;
      // We know that prime numbers have only two divisors i and 1
      s[i] = i + 1;
    }
    else
    {
      s[i] = 1;
      int j = i;
      // d[i] contains the minimum divisor that divides integer i
      while (j % d[i] == 0)
      {
        j /= d[i];
        /*
            we know that d[i] will be prime number and for primes the divisor function is as follows

            prime^r = prime^r + prime^(r-1) + prime^(r-2) + prime^(r-3) + ... + 1.


            for example d(4) => d(2^2) = 2^2 + 2^1 + 2^0;
        */
        s[i] = s[i] * d[i] + 1;
      }

      /*
        After this if j != i then, we know that gcd(j, i) = 1, because of the condition in while loop.

        using multiplicativity of the divisor function d(a * b) = d(a) * d(b) if gcd(a, b) = 1
      */
      s[i] *= s[j];
    }
  }

  fill(ans, ans + MAXN, -1);
  for (int i = MAXN - 1; i > 0; i--)
  {
    if (s[i] < MAXN)
    {
      ans[s[i]] = i;
    }
  }

  int t;
  cin >> t;

  while (t-- > 0)
  {

    int n;
    cin >> n;
    cout << ans[n] << endl;
  }
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

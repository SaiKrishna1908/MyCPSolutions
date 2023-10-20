#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void run()
{
  int a, b, c;
  cin >> a >> b >> c;

  // if already in ap return answer

  if (b - a == c - b)
  {
    cout << "YES" << endl;
  }
  /*
  will changing c give me Ap. If 2*b-c==0 then a must be zero which is not possible
  */
  else if (2 * b - c > 0 && (2 * b - c) % a == 0)
  {
    cout << "YES" << endl;
  }
  /*
  Same as above reason but if ap is in decreasing order
  */
  else if ((2 * b - a) > 0 && (2 * b - a) % c == 0)
  {
    cout << "YES" << endl;
  }
  else if ((a + c) % (2 * b) == 0)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

int main()
{

  // cin.tie(0);
  // cin.sync_with_stdio(false);

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

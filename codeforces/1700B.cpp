#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

void run()
{
  int t;

  cin >> t;

  while (t-- > 0)
  {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int low = 0;
    int high = s.length() - 1;

    int first_num = s[0] - '0';

    // int input_number = from_string(s);

    int nines_res[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
      nines_res[i] = 9 - (s[i] - '0');
    }

    int ones[s.length()];

    if (first_num == 9)
    {
      for (int i = 0; i < s.length() - 1; i++)
      {
        ones[i] = 1;
      }
      ones[s.length() - 1] = 2;

      int carry = 0;
      for (int i = s.length()-1; i >= 0; i--)
      {
        int sum = ones[i] + nines_res[i] + carry;        

        nines_res[i] = sum % 10;
        carry = 1 * (sum / 10);
      }
    }
    for (int i = 0; i < s.length(); i++)
    {
      cout << nines_res[i];
    }
    cout<<endl;
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

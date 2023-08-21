#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

void solve(int n, vector<string> &codes)
{
  if (n == 1)
  {
    codes.push_back("0");
    codes.push_back("1");

    return;
  }

  solve(n - 1, codes);

  int length = codes.size();

  int start_idx = 0;

  if (n > 2)
  {
    for (int i = 1; i < n - 1; i++)
    {
      start_idx += pow(2, i);
    }
  }

  for (int i = start_idx; i < length; i++)
  {
    codes.push_back("0" + codes[i]);
  }

  for (int i = length-1; i >= start_idx; i--)
  {
    codes.push_back("1" + codes[i]);
  }
}

void run()
{
  vector<string> codes;
  int n;
  cin>>n;

  solve(n, codes);


  for(int i=0;i<codes.size();i++) {
    if (codes[i].size() == n) {
      cout<<codes[i]<<endl;
    }    
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

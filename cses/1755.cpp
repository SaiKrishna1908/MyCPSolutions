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

void run()
{
  string s;

  cin >> s;

  map<char, int> map;

  for (int i = 0; i < s.length(); i++)
  {
    map[s[i]] += 1;
  }

  int odd_count = 0;
  char mid_char;

  for (auto pair : map)
  {
    if (pair.second % 2)
    {
      odd_count++;
      mid_char = pair.first;
    }
  }

  char solution[s.length()+1];
  solution[s.length()]  = 0;

  if (s.length() % 2 == 0)
  {
    if (odd_count == 0)
    {
      int low = 0;
      int high = s.length() - 1;
      for (auto pair : map)
      {
        char c = pair.first;
        int count = pair.second;

        while (count > 0)
        {
          solution[low] = c;
          solution[high] = c;
          count -= 2;
          low++;
          high--;
        }
      }

      cout<<solution;
    }
    else
    {
      cout << "NO SOLUTION";
    }
  }
  else
  {
    if (odd_count == 1)
    {
      solution[s.length() / 2] = mid_char;
      map[mid_char]--;
      int low = 0;
      int high = s.length() - 1;
      for (auto pair : map)
      {
        char c = pair.first;
        int count = pair.second;

        while (count > 0)
        {
          solution[low] = c;
          solution[high] = c;
          count -= 2;
          low++;
          high--;
        }
      }

      cout<<solution;
    }
    else
    {
      cout << "NO SOLUTION";
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

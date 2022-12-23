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

void rotate(vector<vector<int>> &matrix)
{
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      if (i != j && i >= j)
      {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }
  }

  int low = 0, high = matrix.size() - 1;

  while (low < high)
  {
    for (int row = 0; row < matrix.size(); row++)
    {
      int temp = matrix[row][low];
      matrix[row][low] = matrix[row][high];
      matrix[row][high] = temp;
    }
    low++;
    high--;
  }
}

void run()
{
  int t;

  cin>>t;
  while (t-- > 0)
  {
    int n;

    cin >> n;

    vector<vector<int>> a(n,vector<int>(n)), a90(n,vector<int>(n)), a180(n,vector<int>(n)), a270(n,vector<int>(n));

    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        char char_element;
        cin>>char_element;

        int element = (char_element - '0');

        a[i][j] = element;        
        a90[i][j] = element;
        a180[i][j] = element;
        a270[i][j] = element;
      }
    }

    rotate(a90);    
    int count = 0;

    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        int count_zero=0, count_ones = 0;

        if (a[i][j] != a90[i][j]) {
          count++;
        }        
      }
    }

    rotate(a180);
    rotate(a180);

    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        int count_zero=0, count_ones = 0;

        if (a90[i][j] != a180[i][j]) {
          count++;
        }        
      }
    }
    rotate(a270);
    rotate(a270);
    rotate(a270);


    cout<<count<<endl;
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

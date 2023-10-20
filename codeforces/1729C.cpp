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


  while(t-->0) {
    string s;

    cin>>s;

    map<char, vector<int>> val_map;

    for(int i=0;i<s.size();i++) {
      val_map[s[i]].push_back(i);
    }

    int direction = s[0] > s[s.length() -1] ? -1 : 1;

    vector<int> positions;

    for(char c = s[0]; c != s[s.length() -1] + direction; c+=direction) {
      for(auto i : val_map[c]) {
        positions.push_back(i);
      }
    }

    int sum = 0; 
    for(int i=1;i<positions.size();i++) {
      sum += abs(s[positions[i-1]] - s[positions[i]]);
    }


    cout<<sum<<" "<<positions.size()<<endl;

    for(int i=0;i<positions.size();i++) {
      cout<<positions[i]+1<<" ";
    }

    cout<<endl;
  }
  
}

int main()
{

  cin.tie(0);
  cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  run();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

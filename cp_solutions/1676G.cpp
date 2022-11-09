#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int t;

  cin>>t;

  while(t-->0) {
    int n;
    cin>>n;

    vector<int> t(n);
    vector<char> c(n+1);

    for(int i=1;i<=n-1;i++) {
      cin>>t[i];
    }    


    for(int i=1;i<=n;i++) {
      cin>>c[i];
    }

    map<int, pair<int, int>> mp;


    for(int i=1;i<=n;i++) {
      mp[i] = make_pair(c[i] == 'W', c[i] == 'B');
    }

    for(int i=2;i<n;i++) {
      c[i] == 'W' ? mp[t[i]].first++ : mp[t[i]].second++; 
    }



    bool is_balanced[n+1];

    
  }
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

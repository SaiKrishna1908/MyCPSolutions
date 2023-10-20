#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin()+1; itr!=arr.end();itr++) {
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

    map<int, vector<int>> mp;

    vector<int> sol(n+1);
    

    for(int i=1;i<=n;i++) {      

      int elem;
      cin>>elem;
      
      if (!mp.count(elem)) {
        vector<int> v;
        v.push_back(i);
        mp[elem] = v;                
      } else {
        mp[elem].push_back(i);
      }      
    }

    for(auto p : mp) {
      int color = p.first;

      int count = 1;
      for(int i=1;i<p.second.size();i++) {
        if (p.second[i] - p.second[i-1] == 1 || ((p.second[i] - p.second[i-1] - 1)%2 == 0)) {
          count++;
        }
      }
      
      sol[color] = count;
    }    

    for(int i=1;i<=n;i++) {
      cout<<sol[i]<<" ";
    }
    cout<<endl;    
  }  
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

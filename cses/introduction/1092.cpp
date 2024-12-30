#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  ll n;

  cin>>n;

  bool is_possible = (n * (n + 1)) % 4 == 0;

  if (!is_possible) {
    cout<<"NO"<<endl;
    return;
  }

  cout<<"YES"<<endl;

  ll sum =  (n * (n+1))/4;


  vector<int> s1;
  vector<int> s2;


  for(int i=n;i>0;i--) {
    if (sum >= i) {
      s1.push_back(i);
      sum = sum - i;
    } else {
      s2.push_back(i);
    }    
  }

  cout<<(s1.size())<<endl;
  for(int i=0;i<s1.size();i++) {
    cout<<s1[i]<<" ";
  }
  cout<<(s2.size())<<endl;
  for(int i=0;i<s2.size();i++) {
    cout<<s2[i]<<" ";
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

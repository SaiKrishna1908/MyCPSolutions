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
  int n,x;
 
  cin>>n>>x;
 
  vector<int> v(n+1);
  vector<int> p(n+1);
 
  for(int i=1;i<=n;i++) {
    cin>>v[i];    
  }
 
  map<ll, int> m;
 
  for(int i=1;i<=n;i++) {
    p[i] = v[i] + p[i-1];
    m[x-p[i]]++;
  }
 
  m[0] = 1;
 
  int count = 0;
  for(int i=1;i<=n;i++) {
    int need = p[i] - x;
    if (m.count(need)) {
        count+=m[need];
    }
  }
 
  cout<<count<<endl;
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
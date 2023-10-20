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
    int n, s;

    cin>>n>>s;

    if (n > s) {
      cout<<"NO"<<endl;
      continue;
    } 

    if (n%2) {
      cout<<"Yes"<<endl;
      cout<<(s  - n + 1)<<" ";

      for(int i=2;i<=n;i++) {
        cout<<1<<" ";
      }
    } else {
      int some_num = s - n + 2;

      if (some_num%2 == 0) {
        cout<<"yes"<<endl;

        cout<<(some_num/2)<<" "<<(some_num/2)<<" ";
        for(int i=3;i<=n;i++) {
          cout<<1<<" ";
        }       
      } else {
        cout<<"no";
      }     
    }

     cout<<endl;
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

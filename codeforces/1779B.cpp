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

    if (n%2 == 0) {
      cout<<"Yes"<<endl;

      for(int i=0;i<n;i++) {
        if (i%2) {
          cout<<-5<<" ";
        } else {
          cout<<5<<" ";
        }
      }

      cout<<endl;
    } else if ( n == 3) {
      cout<<"No"<<endl;
    } else if (n%2) {
      cout<<"Yes"<<endl;
      int k = (n-1)/2;

      for(int i=0;i<n;i++) {
        if (i%2) {
          cout<<(-k)<<" ";
        } else {
          cout<<(k-1)<<" ";
        }
      }          
    }
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

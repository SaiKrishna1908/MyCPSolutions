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

        vector<long> a(n);

        for(int i=0;i<n;i++) {
            cin>>a[i];                               
        }

        vector<long long> b(n);
        bool is_possible = true;
        
                
        b[0] = a[0];

        for(int i=1;i<=n-1;i++) {
            b[i] = a[i]+b[i-1];            
        }

        if (b[n-1] != 0) {
          cout<<"No"<<endl;
          continue;
        }

        for(int i=0;i<n;i++) {
          if (b[i] < 0) {
            is_possible = false;
          } 
        }

        bool contains_zero = false;
        // Check if array is like 2,5,0,0,2,0
        
        for(int i=0;i<n && (i!=-1);i++) {
          if (b[i] == 0 ){
            contains_zero = true;
          } else if (contains_zero) {
            is_possible = false;
          }
        }
        
      
      if (is_possible) {
        cout<<"Yes"<<endl;
      } else {
        cout<<"No"<<endl;
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

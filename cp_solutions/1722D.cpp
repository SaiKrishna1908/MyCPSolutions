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

    char c[n];

    cin>>c;

    int left_pointer = 0;
    int right_pointer = n-1;

    bool isEven = (n%2 == 0);

    ll sum = 0;

    for(int i=0;i<n;i++) {
      sum += (c[i] == 'L' ? (i) : (n-i-1));
    }

    vector<ll> sol;
    
    
    for(int i=0;i<n;i++) {

      if (c[i] == 'L') {
        if (n-i-1 > i) {
          sol.push_back(n-2*i-1);  
        } else {
          sol.push_back(0);
        }           
      } else if (c[i] == 'R') {
        if (i > n-i-1) {
          sol.push_back(2 *i - n +1);
        } else {
          sol.push_back(0);
        }
      }      
    }

    sort(sol.begin(), sol.end());

    for(int i=sol.size()-1;i>=0;i--) {
      sum+=sol[i];   
      cout<<sum<<" ";
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

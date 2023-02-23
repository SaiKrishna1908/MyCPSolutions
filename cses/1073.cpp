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
  int n;
  cin>>n;

  vector<int> x;

  for(int i=0;i<n;i++) {
    int input;
    cin>>input;

    int lb = upper_bound(x.begin(), x.end(), input) - x.begin();

    if (lb >= x.size()) {
      x.push_back(input);
    } else {
      x[lb] = input;
    }    
  }


  // for(auto i=x.begin();i != x.end();i++) {
  //   cout<<(*i)<<endl;
  // }

  cout<<x.size()<<endl;
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

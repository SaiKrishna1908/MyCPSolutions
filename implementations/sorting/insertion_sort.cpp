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
  int n;
  cin>>n;

  vector<int> a(n);

  for(int i=0;i<n;i++) {
    cin>>a[i];
  }

  for(int i=1;i<n;i++) {
    int key = a[i];

    int j = i-1;

    while(j>=0 && a[j] > key) {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        j--;
    }    
  }

  print_vec(a);
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

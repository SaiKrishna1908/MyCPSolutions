#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
  int t;

  cin>>t;

  while(t-->0) {

    string s;
    cin>>s;

    int n = s.length();
    int m = 0;

    vector<bool> bucket(26);

    for(int i=0;i<n;i++) {

      int word_idx = s[i] - 'a';
      if (bucket[word_idx]) {
        fill(bucket.begin(),bucket.end(),false);
        m+=2;
        bucket[word_idx] = false;
      } else {
        bucket[word_idx]= true;
      }
    }

    cout<<(n-m)<<endl;
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

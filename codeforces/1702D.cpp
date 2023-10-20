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
    string s;    

    cin>>s;

    int p;
    cin>>p;

    vector<int> v(s.length());
    
    ll sum = 0;
    map<char, int> del;

    for(int i=0;i<s.length();i++) {      
      v[i] = (s[i]-'a'+1);    
      del[v[i]]++;
      sum += v[i];
    }
    sort(v.begin(), v.end());
    
    long idx = -1;    

    for(int i=s.length()-1 ;i>=0;i--) {
      if (sum <= p) {
        idx = i;        
        break;
      }
      sum-=v[i];
      del[v[i]]--;
    }

    for(int i=0;i<s.length();i++) {
      if (del[s[i]-'a'+1]) {
        del[s[i]-'a'+1]--;
        cout<<s[i];
      }
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

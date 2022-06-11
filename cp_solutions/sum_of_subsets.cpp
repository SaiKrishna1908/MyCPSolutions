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
    int n,k;

    cin>>n>>k;    

    string s;

    cin>>s;


    long sum = 0;

    for(int i=1;i<=s.length()-2;i++) {
      sum += (s[i] - '0') * 11;
    }

    // sum+= (s[0] - '0') * 10;
    // sum+= (s[s.length() -1] - '0');

    int _first_one_post=-1, _last_one_post= -1;

    // replace 0 th with _first_one_position
    // replace s.length()-1 with _last_one_post

    for(int i=0;i<s.length();i++) {
      if (s[i] - '0' == 1) {
        _first_one_post = i;
        break;
      }
    }


    for(int i=s.length()-1;i >=0;i--) {
      if (s[i] - '0' == 1) {
        _last_one_post = i;
        break;
      }
    }

    if (_last_one_post == -1) {
      cout<<0<<endl;
      continue;
    }

    if (_last_one_post == _first_one_post) {
      if ((s.length()-1 - _last_one_post) <= k) {
        cout<<1<<endl;
        continue;
      } else if ((_first_one_post <= k)) {
        cout<<10<<endl;
        continue;
      }
    }

    if (k >= (s.length()-1 - _last_one_post) ) {
      if (s.length()-1 == _last_one_post) {
        sum+=1;     
      }
      else {
        sum-=10;      
        k-=(s.length() - _last_one_post  - 1);      
      }           
    } 

    if (k >= (_first_one_post)  && _first_one_post != s.length()-1) {
      if (_first_one_post == 0) {
        sum+=10;
      } else {
        sum = min(sum-1, sum);      
      }      
    }

    if (sum < 0) {
      cout<<0<<endl;
      continue;
    }
    cout<<sum<<endl;
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

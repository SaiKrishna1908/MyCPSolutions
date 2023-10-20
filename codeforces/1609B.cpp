#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

bool check(char c, int pos , int n, char s[]);


void run() {

  int n,q;
  
  cin>>n>>q;

  char s[n];

  cin>>s;


  int count = 0; 

  for(int i=0;i<n-2;i++) {
    if(s[i] == 'a' and s[i+1] == 'b' and s[i+2] == 'c') {
      count++;
    }
  }

  for(int i=0;i<q;i++) {
    int pos;
    char c;

    cin>>pos;
    cin>>c;


    if(s[pos-1] == c) {
      cout<<count<<endl;
      continue;
    }

    if (check(s[pos-1], pos, n ,s)) {
      count--;
    }


    s[pos-1] = c;

    // cout<<"pos is "<<pos<<" c is "<<c<<" string is "<<s<<endl;

    if (check(s[pos-1],pos, n ,s) ) {
      count++;
    }

    cout<<count<<endl;
  }
}

bool check(char c, int pos , int n, char s[]) {
    
    if (c == 'a' and pos < n-1) {
      if (s[pos] == 'b' and s[pos+1] == 'c') {
        return true;
      }
    } else if (c== 'b' and pos < n and pos > 1) {
      if(s[pos-2] == 'a' and s[pos] == 'c') {
        return true;
      }
    } else if (c == 'c' and pos <= n and pos > 2) {
      if(s[pos-3] == 'a' and s[pos-2] == 'b') {
        return true;
      }
    }

    return false;
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

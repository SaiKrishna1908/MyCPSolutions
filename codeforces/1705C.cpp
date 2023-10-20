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


/*
  for each c
  1. store [ai, bi], where ai is the current appending point and bi is end point
  2. store t = ai - l, where t is the difference to be subtracted for finding the previous string 
  
  for c, c-1, c-2....

  compute the letter 
*/
void run() {
  int t;
  cin>>t;

  while(t-->0) {
    int n,c,q;

    cin>>n>>c>>q;

    char s[n+1];
    cin>>s;

    vector<pair<ll,ll>> cp_operations(c+1);
    vector<ll> offset(c+1);
    vector<pair<ll,ll>> cstsp(c+1);  
    

    cp_operations[0].first = 1;
    cp_operations[0].second = n;

    cstsp[0].first = 1;
    cstsp[0].second = n;

    for(int i=1;i<=c;i++) {
      cin>>cp_operations[i].first;
      cin>>cp_operations[i].second;

      ll ai = cstsp[i-1].second + 1;
      ll bi = ai + (cp_operations[i].second - cp_operations[i].first);

      cstsp[i] = make_pair(ai, bi);

      offset[i] = ai - cp_operations[i].first;
    }

    for(int i=1; i<=q;i++) {
      ll q;
      cin>>q;
          
      for(int j=c;j>=1;j--) {  
        if(cstsp[j].first <= q && cstsp[j].second >= q) {
          q -= offset[j];
        }              
      }

      cout<<s[q-1]<<endl;
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

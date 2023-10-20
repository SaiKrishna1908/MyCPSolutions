#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr);
  }
  cout<<endl;
}


void run() {
  int t;
  cin>>t;

  while(t-->0) {
    int n;
    cin>>n;

    string input_str[n];
    map<string , int> word_map;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
      cin>>input_str[i];
    }

    for(int i=0;i<n;i++) {      
      
      if (word_map.count(input_str[i])) {
        v[i] = 1;
        v[word_map[input_str[i]]] = 1;
      } else {
        word_map[input_str[i]] = i;
      }      
    }    


    

    for(int i=0;i<n;i++) {
      string s = input_str[i];

      bool is_possible = false;         


      if (s.length() == 1) {
        v[i] = 0;
      }   

      for(int idx = 1;idx<=s.length();idx++) {
        string x = s.substr(0, idx);
        string y = s.substr(idx, s.length());

        if (word_map.count(x) && word_map.count(y)) {
          is_possible = true;
          break;
        }        
      }

      if (is_possible) {
        v[i] = 1;
      } else {
        v[i] = 0;
      }
      
    }


    print_vec(v);
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

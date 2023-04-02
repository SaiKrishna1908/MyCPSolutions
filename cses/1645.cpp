#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin()+1; itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}


void run() {
  int n;
  cin>>n;

  vector<pair<int,int>> v(n);

  for(int i=0;i<n;i++) {
    int input;
    cin>>input;

    v[i] = make_pair(input, i+1);
  }  

  stack<pair<int,int>> m_stack;

  for(int i=0;i<n;i++) {
    if (m_stack.empty()) {
      cout<<0<<" ";
      m_stack.push(v[i]);
    } else {

      auto top = m_stack.top();

      if (top.first < v[i].first) {
        cout<<top.second<<" ";
        
      } else {              
        while(top.first >= v[i].first) {
          m_stack.pop();
          if (m_stack.empty()) {
            
            break;
          }
          top = m_stack.top();
        }        
        if (m_stack.empty()) {
          cout<<0<<" ";
        } else {
          cout<<top.second<<" ";
        }        
      }
      m_stack.push(v[i]);
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

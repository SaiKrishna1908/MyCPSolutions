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

    map<int, vector<int>> mp; 

    vector<int> re(n+1);
    vector<char> color(n+1);

    map<int, pair<int, int>> output;

    for(int i=2;i<=n;i++) {
      int elem;
      cin>>elem;
      re[i] = elem;  
      mp[elem].push_back(i);
    }

    for(int i=1;i<=n;i++) {      
      cin>>color[i];
    }

    stack<int> st[n+1];

    stack<int> outstack[n+1];

    st->push(1);

    while(!st->empty()) {

      int top = st->top();
      st->pop();
      
      for(auto elem : mp[top]) {
        st->push(elem);
      }      

      outstack->push(top);
      
      
    }

    while(!outstack->empty()) {
      int el = outstack->top();
      outstack->pop();

      int wc = color[el] == 'W';
      int bc = color[el] == 'B';
      output[el] = output.count(el) ? make_pair(output[el].first + wc, output[el].second + bc) : make_pair(wc,bc);

      // change parent as well


      if (el == 1) {
        continue;
      }
      if (output.count(re[el]) ) {
        output[re[el]].first += output[el].first;
        output[re[el]].second += output[el].second;
      } else {
        output[re[el]].first = output[el].first;
        output[re[el]].second = output[el].second;
      }

      
    }

    int count = 0;

    for(auto x : output) {
      if (x.second.first == x.second.second) {
        count++;
      }
    }

    cout<<count<<endl;
  }
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  // auto start = high_resolution_clock::now();
  
  run();
  
  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

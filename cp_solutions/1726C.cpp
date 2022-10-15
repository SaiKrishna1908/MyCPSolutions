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
  // 1. Given i, j determine if a[i], a[i+1],..., a[j] is a balanced sequence

  int t;

  cin>>t;

  while(t-->0) {

    int n;

    cin>>n;

    string s;
    cin>>s;
    stack<int> st;

    // count of open brackets
    int cnt = 0;

    // Always balanced,
    int ans = 1;

    for(int i=0;i<2*n+1;i++) {
      if (s[i] == '(')  {
        cnt++;
        st.push(i);        
      } else if (s[i] == ')') {
        cnt--;
        /*
          Why s[st.top() - 1] != ')' ? 

          Take the below  problem as example
          (()())

          Here when we compute logic for index 4, we need to check if this is
          a part of container i.e (2,3) and (4,5) here become one part.

          If the character before the index which is on top of stack is ')' we know that this 
          balanced seq has a sibling otherwise it is a child sequence like (())
        */        
        if (cnt != 0 && s[st.top() - 1] != ')') {
          ans++;          
        }

        st.pop();       
      }
    }

    cout<<ans<<endl;  
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

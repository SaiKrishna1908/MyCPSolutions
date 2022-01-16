#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

bool isPalindrome(vector<int> v2) {

  int low = 0;
  int high = v2.size()-1;


  while(low < high) {
    if(v2[low] != v2[high]) {
      return false;
    }

    low++;
    high--;
  }

  return true;
}


void run() {

  int n;
  cin>>n;

  vector<int> v1(n);
  bool isPalindrome(vector<int> v2);


  for (int i=0;i<n;i++) {
    cin>>v1[i];
  }

  int low = 0;
  int high = n-1;

  if(n == 1) {
    cout<<"YES"<<endl;
    return;
  }

  if (isPalindrome(v1)) {
    cout<<"YES"<<endl;
    return;
  }

  while(low < high) {

    if (v1[low] != v1[high]) {
      vector<int> v2(n);

      remove_copy(v1.begin(), v1.end(), v2.begin(), v1[low]);
      auto itr = remove(v2.begin(), v2.end(), 0);
      v2.erase(itr, v2.end());

      if(v2.size() == 1 ){
        cout<<"YES"<<endl;
        return;
      }

      if (isPalindrome(v2)) {
        cout<<"YES"<<endl;
        return;
      }

      vector<int> v3(n);

      remove_copy(v1.begin(), v1.end(), v3.begin(), v1[high]);
      itr = remove(v3.begin(), v3.end(), 0);
      v3.erase(itr, v3.end());

      if(v3.size() == 1) {
        cout<<"YES"<<endl;
        return;
      }

      if (isPalindrome(v3)) {
        cout<<"YES"<<endl;
        return;
      }

      break;
    }

    low++;
    high--;
  }
  
  cout<<"NO"<<endl;
  
}

int main() {

  cin.tie(0);
  cin.sync_with_stdio(false);
    

  int t;

  cin>>t;

  while(t-->0) {
    run();
  }
  
}

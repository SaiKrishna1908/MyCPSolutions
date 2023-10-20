#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long



int is_bad(vector<int> a){



  int sum=0;

  for(int i : a)
    sum+=i;

  if(sum&1)
    return 0;
    
  bitset<200005> b;
  b[0] = 1;

  for(int i=0;i<a.size();i++)
    b = b | (b<<a[i]);



  return b[sum/2];
  
}

int main() {

  int n, sum=0;

  cin >> n;
  
  vector<int> a(n);

  for(int i=0;i<n;i++)
    cin>>a[i];

  // is_bad returns 0 if sum of array is odd.
  if(is_bad(a)){

    pair<int, int> mn(20,0);

    for(int i=0;i<a.size();i++){
      mn = min(mn, make_pair(__builtin_ctz(a[i]),i+1));
    }

    cout<<1<<"\n";
    cout<<mn.second;
  }
  else {
    cout<<0;
  }
  
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()




void run() {
    
  int n;

  // nth ugly number
  cin>>n;


  vector<int> res;

  res.push_back(1);

  int i2=0,i3=0,i5=0;  


  for(int i=0;i<n;i++) {

    int two_count = res[i2] * 2;
    int three_count = res[i3] * 3;
    int five_count = res[i5] * 5;

    int min_count = min(two_count, min(three_count,five_count));


    if(two_count == min_count) {
      i2++;
    }

    if ( three_count == min_count) {

      i3++;
    }

    if(five_count == min_count) {
      i5++;
    }

    res.push_back(min_count);

  }

  cout<<res[n-1];
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  run();
}

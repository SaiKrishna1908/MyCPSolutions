#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

/*
  Perfect squares lie on one of the borders
  Each perfect square makes a layer in shape of L
  Which layer are the present co-ordinates there in ? -> max(r, c)
  What is the number present in (layer, layer) co-ordinate -> layer*layer - (layer - 1)
  Offset = (layer, layer) - (r, c)
  Using the above facts we can determine if ans is 

  ((layer*layer) - (layer-1)) + offset
  ((layer*layer) - (layer-1)) - offset
*/
void run() {
  
  int n;
  cin>>n;

  while(n-->0) {
    ll r,c;

    cin>>r>>c;

    ll layer = max(r,c);

    ll ell = (layer * layer) - (layer - 1);

    if (r == 1 && c== 1) {
      cout<<1<<endl;
      continue;
    }

    /*
      If layer is even 
      
    */
    ll offset = (layer - r) + (layer -c);
    if (layer % 2) {
      if (r != layer) {
        cout<<(ell+offset)<<endl;
      } else {
        cout<<(ell-offset)<<endl;
      }
    } else {
      if (r != layer) {
        cout<<(ell-offset)<<endl;
      } else {
        cout<<(ell+offset)<<endl;
      }
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

#include <iostream>
#include <bits/stdc++.h>

void solve();
using namespace std;

#define ll long long

int main () {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;

  cin >> t;


  while(t-->0) {
    solve();
  }
}

void solve() {

  int n;

  cin >> n;

  vector<ll> a(n), pos(n+1), res(n);
  vector<bool> used(n+1), visited(n+1);
  set<ll> avail;

  ll total=0;

  
  for(int i=0;i<n;i++) {
    cin>>a[i];
    avail.insert(i+1);
    
  }

  for(int i=0;i<n;i++) {
    if(!used[a[i]]) {

      avail.erase(a[i]);
      pos[a[i]] = i;
      used[a[i]] = 1;
      visited[i] = 1;
      total++;
    }
  }

  for(int i=0;i<n;i++) {

    if(!visited[i]) {

      auto itr = avail.begin();


      if((*itr) != (i+1))  {

	a[i] = *itr;
	used[a[i]] = 1;
	pos[a[i]] = i;
       
      }
      else {

	ll p = pos[a[i]];
	a[i] = (*itr);
	swap(a[i], a[p]);
	pos[a[i]] = i;
	pos[a[p]] = p;
      }
      avail.erase(itr);
    }
  }

  cout<<total<<endl;

  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
}


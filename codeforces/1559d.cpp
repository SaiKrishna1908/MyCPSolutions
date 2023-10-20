#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


int forest[2][1005];


void  make_set() {

  for(int i=1;i<1005;i++) {

    forest[0][i] = i;
    forest[1][i] = i;
  }
  
}

int my_find(int fid, int n) {

  if (forest[fid][n] == n) {
    return n;
  }
  
  return my_find(fid, forest[fid][n]);
}

void my_union(int fid, int parent, int elem) {

  int current_parent = my_find(fid, elem);
  int new_parent = my_find(fid, parent);

  
  forest[fid][current_parent] = new_parent;
  forest[fid][elem] = new_parent;
}

void run() {

  make_set();

  int n,m1,m2;
  cin>>n>>m1>>m2;

  int count=0;

  vector<pair<int,int>> res;

  for(int i=0;i<m1;i++) {
    int l,r;

    cin>>l>>r;

    if (my_find(0,l) != my_find(0,r) ){
      my_union(0, l,r);
    }
  }

  for(int i=0;i<m2;i++) {
    int l,r;

    cin>>l>>r;

    
    if (my_find(1,l) != my_find(1,r) ) {
      my_union(1, l,r);
    }
  }

  

  for(int i=1;i<=n;i++) {

    for(int j=1;j<=n;j++) {

      if(my_find(0, i) != my_find(0, j) && my_find(1,i) != my_find(1,j)) {

	count++;


	res.push_back(make_pair(i,j));

	my_union(0,i,j);
	my_union(1,i,j);

      }
    }
  }

  cout<<count<<endl;

  for(auto a: res) {
    cout<<a.first<<" "<<a.second<<endl;
  }

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //  cout<<fixed;
  //  cout<<setprecision(10);

  run();
}

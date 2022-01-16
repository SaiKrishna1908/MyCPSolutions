#include <iostream>
#include <bits/stdc++.h>

void build(int a[],int v,int tl ,int tr);
int sum(int v, int tl, int tr, int l, int r);

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int MAXN = 10e5;

int t[100];

int main() {

  int a[] = {-1,5,4,3,7,8,10,12};

  build(a, 1, 1, 7);

  cout<<sum(1,1,7,2,7);
}

void build(int a[], int v, int tl, int tr){

  if(tl == tr) {

    t[v] = a[tl];
 }
  else {

    int mid = (tl+tr)/2;

    build(a,2*v, tl, mid);
    build(a,2*v+1, mid+1, tr);

    t[v] = t[v*2] + t[v*2+1];
    
  }      
}



int sum(int v, int tl, int tr, int l, int r) {


  if(l > r) {
    return 0;
  }

  if(l == tl && r == tr) {
    return t[v];
  }

  int tm = (tl + tr) /2 ;

  return sum(v*2, tl,tm, l , tm) + sum(v*2+1, tm+1, tr, tm+1, r);
    
}
  
  

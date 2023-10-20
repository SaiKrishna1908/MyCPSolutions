#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValid(int i, int j);

#define ll long long

int h,w;
int arr[21][21];

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;

  cin >> t;

  while(t--> 0) {



    for(int i=0;i<21;i++)
      for(int j=0;j<21;j++)
	arr[i][j] = 0;



    cin>>h>>w;

    for(int i=1;i<=h;i++) {
      for(int j=1;j<=w;j++) {

	if(isValid(i,j)) {
	  arr[i][j] = 1;
	}
      }
    }

    for(int i=1;i<=h;i++) {
      for(int j=1;j<=w;j++) {

	cout<<arr[i][j];

      }
      cout<<endl;
    }
  }
}


bool isValid(int i, int j) {

  if( (i==1 || i == h) || (j==1 || j==w)) {

    for(int x=-1;x<2;x++) {
      for(int y=-1;y<2;y++) {
	if( i+x <= h && j+y <= w && i+x >= 1 && j+y >= 1) {

	  if (arr[i+x][j+y] == 1)
	    return false;
	}
	
      }
    }

    return true;
  }
  return false;
}

  

  

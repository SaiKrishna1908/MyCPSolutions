#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int MAX_ = 2050;


typedef struct tree {

  struct node *left;
  struct node *right;
  int data;
} node;

node *root;
  


int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,t;

  int a[MAX_];

  cin>>n;
  
  int left, right;

  for(int i=1;i<=n;i++){
    
    cin>>left>>right;

    if(a[i] == -1){

      while(a[i] == -1)
	i++;
    }

    a[2*i] = left;
    a[2*i+1] = right;
    
  }

  cout<<n;


  for(int i=1;i<=n;i++){
    cout<<"parent is"<<a[i]<<"\n"<<"left child is "<<a[2*i]<<"  "<<"Right child is"<<a[2*i+1];
    cout<<"\n";
  }
}

	   

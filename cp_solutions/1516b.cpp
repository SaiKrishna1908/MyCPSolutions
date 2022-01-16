#include<iostream>
#include<bits/stdc++.h>

using namespace std;


#define ll long long


int main() {
  

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed;
  cout<<setprecision(10);


  int t;

  cin >> t;

  while(t-->0){

    int n;

    cin>>n;

    vector<int> a(n);

    int xr= 0;



    for(int i=0;i<n;i++){
      cin >> a[i];
      xr ^= a[i];
    }

    if(xr==0)
      cout<<"YES\n";

    else{
      
      int c = 0,temp=0;

      for(int i=0;i<n;i++){
	temp = temp^ a[i];

	if(temp == xr){
	  c++;
	  temp=0;
	}
	  
      }
    

      if(c>=3)
	cout << "YES\n";
      else
	cout << "NO\n";
    }
      
    }
  return 0;
    
  }
	      
    

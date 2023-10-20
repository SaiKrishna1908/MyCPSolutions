#include <iostream>
#include <bits/stdc++.h>


using namespace std;

#define ll long long

const int N = 10e5+1000;
int arr[N];


void precalc() {
  
  for(int i=0;i<N;i++) {
    arr[i] = i - i/4;
  }
  
}

int main() {

  cin.tie(0);
  cout.tie(0);

  precalc();

  int t;

  cin>>t;
    

  while (t--> 0) {

  
    int n;

    cin>>n;

    int mibuck[101];
    int libuck[101];


    for(int i=0;i<101;i++) {
      mibuck[i] = 0;
      libuck[i] = 0;
    }


    for(int i=0;i<n;i++) {
      int temp;
      cin>>temp;
      mibuck[temp]++;
    }



    for(int i=0;i<n;i++) {

      int temp;
      cin>>temp;
      libuck[temp]++;
    }


    int count = 0;

    while (true)  {

      int n_t = n+count;

      int sum1=0;
      int sum2=0;

      int temp = 0;

      int idx = 100;



      while(temp < arr[n_t] && idx > 0) {

	if(temp + mibuck[idx] > arr[n_t] ) {
	  sum1 = sum1+idx*(arr[n_t]-temp);
	  break;
	}

	sum1 = sum1 + mibuck[idx]*idx;
	temp = temp + mibuck[idx];
	idx--;
      }

      temp = 0;
      idx =100;

      while(temp < arr[n_t] && idx > 0) {

	if(temp + libuck[idx] > arr[n_t] ) {
	  sum2 = sum2+idx*(arr[n_t]-temp);
	  break;
	}


	sum2 = sum2 + libuck[idx]*idx;
	temp = temp + libuck[idx];
	idx--;
      }


      
      if(sum2 > sum1) {
	count++;
	mibuck[100]++;
	
      }
      else {
	break;
      }
	
    }

    //cout<<"count is "<<count<<endl;


    cout<<count<<endl;


    
  }
  
}

#include <iostream>
#include <bits/stdc++.h>

#define ll long long;

using namespace std;

const int N = 40000;

bool isPrime[N];
vector<int> primes;

void sieve() {

  fill(isPrime+2, isPrime+N, true);

  for(int i=2;i*i<N;i++) {

    for(int j=i*i;j<=N;j=j+i) {

      isPrime[j]  = false;
    }
  }

  for (int i=0;i<N;i++) {

    if(isPrime[i]) {
      primes.push_back(i);
    }
      
  }
    
    
}


int calcPrimes(int n) {

  int count = 0 ;

  for(int i : primes) {

    if(i*i > n)
      break;

    while ( n%i == 0 ){

      n = n/i;
      count++;
    }
  }

  if(n > 1)
    count++;


  return count;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  sieve();

  int t;

  cin>>t;

  while(t-->0) {

    int a,b,k;

    cin>>a>>b>>k;



    if(k == 1) {

      if(a!=b && (a%b ==0 || b%a == 0)) {
	cout<<"YES\n";

      }
      else {
	cout<<"NO\n";
      }
      continue;
    }


    int aprimes = calcPrimes(a);
    int bprimes = calcPrimes(b);

    if(aprimes + bprimes >=k) {
      cout<<"YES\n";
    }
    else {

      cout<<"NO\n";
    }

  }

  return 0;
}


#include <iostream>
#include <bits/stdc++.h>

using namespace std;


#define long long ll


bool is_primes[1001];

vector<int> primes;

int N = 1'001;

void sieve() {

  fill(is_primes+2,is_primes+N,true);

  for(int i=2;i*i < N;i++) {
    for( int j=i*i;j<N;j=j+i) {

      is_primes[j] = false;
    }
  }

  for(int i=0;i<N;i++)
    if(is_primes[i])
      primes.push_back(i);
  
}

int calcPrimes(int n) {

  int res = 0;

  for(int i : primes) {

    if(i*i > n) {
      break;
    }

    while(n%i == 0) {

      n = n/i;
      res++;
      
    }
  }

  if(n>1)
    res++;

  return res;
}

map<int, int> decompose(int n) {

  map<int, int>  factors;

  for(int i: primes) {

    if(i*i> n)
      break;

    int p = 0;
    while(n%i == 0) {
      n=n/i;
      p++;
    }

    if(p>0) {
      factors.insert(pair<int,int>(i, p));
    }
      
  }

  if(n>1)
    factors.insert(pair<int,int>(n,1));

  return factors;
}


void solve() {

  int a,b;

  cin>>a>>b;

  int g = __gcd(a,b);

  int low = 0;
  int high = 0;

  {

    int t;
    int ta=1;

    while((t= __gcd(a,g)) != 1) {

      a/=t;
      ta*=t;
    }

    high+= calcPrimes(a);

    if(a!=1) {

      low |= 1;
    }    

    a = ta;
  }

  {
    int t;
    int tb = 1;

    while((t= __gcd(b,g)) != 1) {

      b/=t;
      tb*=t;
    }

    high += calcPrimes(b);

    if( b!= 1) {
      low |= 2;
    }
    b=tb;
  }

  cout<<"a is: "<<a<<" b is: "<<b<<"\n";

  cout<<"low is: "<<low<<" High is: "<<high;

  auto divs = decompose(g);
  auto divA = decompose(a);
  auto divB = decompose(b);

 
    
}

int main() {

  sieve();

  int result = calcPrimes(111);
  //  map<int,int> factors = decompose(108);

  //  for (map<int,int>::iterator itr = factors.begin(); itr!=factors.end();itr++)
  //cout<<itr->first<<": "<<itr->second<<"\n";
  cout<<result;

  //solve();
}





#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {

	int a,b,c;

	cin>>a>>b>>c;

	int an=0,bn=0,cn=0;

	int maxi = max(a,max(b,c));


  	if (a <= maxi) {

  		if((a==b or a==c) and a == maxi) {
  			an = 1;
  		} else if(a!=maxi) {
  			an = maxi -a +1;
  		}

  	}

  	if (b <= maxi) {

  		if((b==a or b==c) and b == maxi) {
  			bn = 1;
  		} else if (b != maxi){
  			bn= maxi-b+1;
  		}  		
  	}
  	if (c <= maxi) {

  		if((c==a or b==c) and c == maxi) {
  			cn = 1;
  		} else if (c!= maxi){
  			cn=maxi-c+1;
  		}  		
  	}

  	cout<<an<<" "<<bn<<" "<<cn<<endl;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed;
  cout<<setprecision(10);

  int t;

  cin>>t;

  while(t-->0) {
  	run();
  }

  
}

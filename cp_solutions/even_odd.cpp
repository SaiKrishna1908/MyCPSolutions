#include <bits/stdc++.h>
using namespace std;

int main(){

	 // ios::sync_with_stdio(!cin.tie(0));
	
	int t;

	cin>>t;

	while(t-->0){

		int n;

		cin>>n;


		vector<int> a(n);

		

		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(begin(a), end(a), greater<int>());

		long long tot_diff = 0;

		int chance = 0;

		for(int i=0;i<n;i++){

			if(chance == 0){
				if((a[i] % 2) == 0){
					tot_diff+=a[i];
				}

			}
			else {
				if((a[i] % 2) == 1){
					tot_diff-=a[i];
				}
			}

			chance^=1;
		}
		
		if(tot_diff > 0)
			cout<<"Alice\n";
		else if(tot_diff < 0)
			cout<<"Bob\n";
		else 
			cout<<"Tie\n";

	}

	return 0;
}
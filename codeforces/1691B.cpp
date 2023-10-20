#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()


void run() {
    int n;
    cin>>n;

    while(n-->0) {
        int k;
        cin>>k;
        vector<int> shoe_size(k+1);
        vector<int> sol(k);

        for(int i= 1;i<=k;i++) {
            cin>>shoe_size[i];
        }

        int curr_index = 0;
        for(int i=1;i<k;i++) {
            if ( (shoe_size[i] == i && shoe_size[i+1] != shoe_size[i] ) || shoe_size[k] > k) {
                cout<<-1<<endl;
                goto OUTER;
            }
        }

        for(int i=1;i<k;i++) {
            int rep_count = 0;
            int temp = i;
            while(temp<=k && shoe_size[temp] == shoe_size[temp+1]) {
                rep_count++;
                temp++;
            }
            cout<<(i+rep_count)<<" ";

            for(int j=i;j<=rep_count;j++) {
                cout<<j<<" ";
            }
            i+=rep_count;
        }
        cout<<endl;
    OUTER:;
    }
}

int main() {

  // cin.tie(0);
  // cin.sync_with_stdio(false);
    

  auto start = high_resolution_clock::now();
  
  run();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void print_vec(vector<int> arr)
{
  for (auto itr = arr.begin(); itr != arr.end(); itr++)
  {
    cout << (*itr) << " ";
  }
  cout << endl;
}

// Expected 6, found 5
void run()
{
  int t;
  cin >> t;

  while (t-- > 0)
  {
    int n;
    cin >> n;

    // pref -> number of distinct elements till i
    // pref_completed -> number of distinct elements which completed their freq till i
    vector<int> v(n), pref(n+1, 0), pref_completed(n+1,0);

    // max_freq -> what is the total frequency of a number in array
    // freq -> temporary array to store frequency in iteration
    map<int, int> max_freq, freq;

    for(int i=0;i<n;i++) {
      cin>>v[i];
      max_freq[v[i]]++;
    }    

    for(int i=0;i<n;i++) {
      // New number found at ith place
      if (freq.find(v[i]) == freq.end()) {
        freq[v[i]] = 1;
        pref[i+1] = pref[i] + 1;
      }
      // Number already exists
       else {
        freq[v[i]]++;
        pref[i+1] = pref[i];
      }      

      if (freq[v[i]] == max_freq[v[i]]) {
        pref_completed[i+1] = pref_completed[i]+1;
      } else {
        pref_completed[i+1] = pref_completed[i];
      }
    }

    ll ans = pref[n], last = INT_MAX;

    for(int i=n-1;i>=0;i--) {

      if (v[i] > last) {
        break;
      }

      if (pref[i] == pref_completed[i]) {
        ans = pref[i];
      }

      last = v[i];
    }

    cout<<ans<<endl;    
  }
}

int main()
{

  cin.tie(0);
  cin.sync_with_stdio(false);

  auto start = high_resolution_clock::now();

  run();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // cout<<"time: "<<duration.count()/1e6<<endl;
}

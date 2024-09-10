#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9+7

template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);
struct debug {
    
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return * this; }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return * this << range(begin(i), end(i)); }
    template < class c, class b > debug & operator <<(pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
    
};

void print_vec(vector<int> arr) {
  for(auto itr = arr.begin(); itr!=arr.end();itr++) {
    cout<<(*itr)<<" ";
  }
  cout<<endl;
}

int isAscendingNumber(int number) {
    int prev = 0;    
    while(number > 0) {
        int current_number = number % (int) pow( 10, floor(log10(number)));
        if (current_number < prev) {
            return false;
        }
        number = number /  10;
    }

    return true;
}

int getFirstDigit(float number) {
    auto e = floor(log10(number));
    if (number < e || number == 0) {
        return number;
    }
    return number /  pow(10, e);
}

int getLastDigit(int number) {
    auto e = floor(log10(number));
    if (e == 0 || number == 0) {
        return number;
    }
    double dividend = pow(10.0, e);
    return number % (int)dividend;    
}

void run() {
  int t;

  cin>>t;
  
  while(t-- > 0) {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    bool isNotPossible = false;

    for(int i=1;i<arr.size();i++) {
        int lastDigit = getLastDigit(arr[i-1]);
        int firstDigit = getFirstDigit(arr[i]);
        if ((lastDigit > firstDigit) || (!isAscendingNumber(arr[i])) ) {
            isNotPossible = true;
            cout<<"NO"<<endl;
            break;
        }
    }

    if (!isNotPossible) {
        cout<<"Yes"<<endl;
    }    
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

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

void run()
{
    int n;
    cin >> n;
    bool primes[n + 1];

    fill(primes, primes + n + 1, true);

    for(int i=2;i * i < (n+1); i++) {
        if (primes[i] == true) {
            for(int j = i*i; j < (n);j+=i) {
                primes[j] = false;
            }
        }
    }

    for(int i=2;i<n;i++) {
        cout<<"{ "<<i<<", "<<primes[i]<<"}"<<endl;
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

    cout<<"time: "<<duration.count()/1e6<<endl;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

struct matrix
{
    ll m[3][3];
};

matrix I = {
    1, 0, 0, 0, 1, 0, 0, 0, 1};

matrix A = {
    3, -1, 1, 1, 0, 0, 0, 0, 1};

void run()
{
    ll n;

    cin >> n;

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    if (n == 2)
    {
        cout << 1 << endl;
        return;
    }
}

int main()
{

    // cin.tie(0);
    // cin.sync_with_stdio(false);

    auto start = high_resolution_clock::now();

    run();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // cout<<"time: "<<duration.count()/1e6<<endl;
}

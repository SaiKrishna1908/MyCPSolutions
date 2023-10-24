/*
    Given an array of elements, find different
    sums which are possible using the elements.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

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
    vector<int> a;

    int n, sum;

    cin >> n >> sum;

    a.push_back(3);
    a.push_back(1);
    a.push_back(5);

    vector<int> sums;

    // b[i] is 1 if sum i can be constructed from the subset of the array
    bitset<200005> b;
    b.reset();

    // b[0] is 1, because 0 is always possible with empty set
    b[0] = 1;

    for (auto e : a)
    {
        /*
            Do OR of following two
            1) All previous sums. We keep previous value
            of bit.
            2) arr[i] added to every previous sum. We
            move all previous indexes e ahead.
        */
        b = b | (b << e);
    }

    cout << b[sum] << endl;
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

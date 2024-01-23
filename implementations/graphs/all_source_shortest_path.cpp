#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
const int INF = 1e7 + 7;

template <class c>
struct rge
{
    c b, e;
};
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug
{

    ~debug() { cerr << endl; }
    template <class c>
    typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i)
    {
        cerr << boolalpha << i;
        return *this;
    }
    template <class c>
    typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
    template <class c, class b>
    debug &operator<<(pair<b, c> d)
    {
        return *this << "(" << d.first << ", " << d.second << ")";
    }
    template <class c>
    debug &operator<<(rge<c> d)
    {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return *this << "]";
    }
};

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

    int n = 4, m = 4;

    int matrix[n][m] = {{0, 3, 8, INF}, {INF, 0, INF, 1}, {INF, 4, 0, INF}, {2, INF, -5, 0}};
    int iter = 0;
    // while (iter < n)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             for (int k = 0; k < n; k++)
    //             {
    //                 matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
    //             }
    //         }
    //     }
    //     iter++;
    // }

    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
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

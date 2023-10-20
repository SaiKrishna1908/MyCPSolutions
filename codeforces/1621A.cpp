#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void run()
{

    int n, k;

    cin >> n >> k;

    int pos_n = (int)ceil((double)n / 2);

    // cout << pos_n << endl;

    if (pos_n < k)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (i == j && (i & 1) && (k > 0))
            {
                cout << 'R';
                k--;
            }
            else
            {
                cout << '.';
            }
        }

        cout << endl;
    }

    cout << endl;
}

int main()
{

    // cin.tie(0);
    // cin.sync_with_stdio(false);

    //   auto start = high_resolution_clock::now();

    int t;

    cin >> t;

    while (t-- > 0)
    {
        run();
    }

    //   auto stop = high_resolution_clock::now();
    //   auto duration = duration_cast<microseconds>(stop - start);

    // cout<<"time: "<<duration.count()/1e6<<endl;
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

void run()
{
    int n;

    cin >> n;

    vector<ll> a(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    bool used[n + 1];

    fill(&used[0], &used[0] + sizeof(used), false);

    for (int i = 1; i <= n; i++)
    {
        // Greedly operate only on elements that are more than n       
            // Keep dividing them by 2 until they are >= 1
            while (a[i]  >= 1)
            {                

                // In case we find a number that is not present that is less than n
                if (a[i] <= n && !used[a[i]] ) {
                    break;
                }
                a[i] = floor((double)a[i] / 2);                                           
            }                    
        used[a[i]] = true;
    }



    for (int i = 1; i <= n; i++)
    {

        if (!used[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{

    cin.tie(0);
    cin.sync_with_stdio(false);

    auto start = high_resolution_clock::now();

    int t;

    cin >> t;

    while (t-- > 0)
    {
        run();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // cout<<"time: "<<duration.count()/1e6<<endl;
}

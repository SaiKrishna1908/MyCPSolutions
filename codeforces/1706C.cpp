#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

const int MAX = 1e5 + 7;
int a[MAX];

void print_vec(vector<int> arr)
{
    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

ll get(int i)
{
    return max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
}

void run()
{

    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        ll tot_cost = 0;

        if (n % 2)
        {
            for (int i = 2; i < n; i+=2)
            {
                tot_cost += get(i);
            }

            cout<<tot_cost<<endl;
        } else {
            for(int i=2;i<n;i+=2) {
                tot_cost += get(i);
            }

            ll ans = tot_cost;

            for(int i=n-1;i>1;i-=2) {
                
                tot_cost -= get(i-1);
                tot_cost += get(i);

                ans = min(ans, tot_cost); 
            }
            cout<<ans<<endl;               
        }

        
    }
}

int main()
{

    // cin.tie(0);
    // cin.sync_with_stdio(false);

    // auto start = high_resolution_clock::now();

    run();

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);

    // cout<<"time: "<<duration.count()/1e6<<endl;
}

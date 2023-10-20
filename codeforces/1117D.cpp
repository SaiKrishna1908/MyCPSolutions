#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()

const ll MOD = 1e9 + 7;

struct matrix
{
    ll mat[2][2];
};

matrix I = {
    1, 0, 0, 1};

matrix A = {
    3, 1, 1, 3};

matrix multi(matrix a, matrix b)
{

    matrix c;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c.mat[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c.mat[i][j] = c.mat[i][j] + a.mat[i][k] * b.mat[k][j] % MOD;
            }
            c.mat[i][j] %= MOD;
        }
    }
    return c;
}

matrix power(ll power)
{

    matrix ans = I, temp = A;

    while (power)
    {
        // if odd cannot do power/2
        if (power & 1)
            ans = multi(ans, temp);

        temp = multi(temp, temp);
        power >>= 1;
    }

    return ans;
}

void run()
{

    ll n;

    cin >> n;
    matrix ans = power(n);
    cout << ans.mat[0][0];
}

void display(ll final_state[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << final_state[i][j] << " ";
        }
        cout << endl;
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

    // cout << "time: " << duration.count() / 1e6 << endl;
}

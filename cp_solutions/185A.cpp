#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
struct matrix
{
    LL m[2][2];
};
matrix I = {
    1, 0,
    0, 1};
matrix A = {
    3, 1,
    1, 3};
matrix multi(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c.m[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c.m[i][j] = c.m[i][j] + a.m[i][k] * b.m[k][j] % mod;
            }
            c.m[i][j] %= mod;
        }
    }
    return c;
}
matrix power(LL p)
{
    matrix ans = I, temp = A;
    while (p)
    {
        if (p & 1)
            ans = multi(ans, temp);
        temp = multi(temp, temp);
        p >>= 1;
    }
    return ans;
}
int main()
{
    LL n;
    while (cin >> n)
    {
        matrix ans = power(n);
        cout << ans.m[0][0] << endl;
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define ll long long
#define all(v) v.begin(), v.end()
#define INF 1e9 + 7

int MAX = 20005;

vector<int> a(MAX);

void print_vec(vector<int> arr)
{
    for (auto itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

void merge(int left, int mid, int right)
{

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> l;
    vector<int> r;

    for (int i = left; i <= mid; i++)
    {
        l.push_back(a[i]);
    }

    for (int i = mid + 1; i <= right; i++)
    {
        r.push_back(a[i]);
    }

    int currentIdx = left;
    int lp = 0;
    int rp = 0;

    while (lp < leftSize && rp < rightSize)
    {
        bool islm = (l[lp] == min(l[lp], r[rp]));

        if (islm)
        {
            a[currentIdx] = l[lp];
            lp++;
        }
        else
        {
            a[currentIdx] = r[rp];
            rp++;
        }
        currentIdx++;
    }

    if (lp < mid)
    {
        for (int i = lp; i < mid; i++, currentIdx++)
        {
            a[currentIdx] = l[lp];
        }
    }
    else if (rp < right)
    {
        for (int i = rp; i < right; i++, currentIdx++)
        {
            a[currentIdx] = r[rp];
        }
    }
}

void mergeSort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    merge(l, mid, r);
}

void run()
{
    // int n;
    // cin >> n;

    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> a[i];
    // }

    int n = 3;

    for(int i=1;i<=n;i++) {
        a[i] = n-i+1;
    }

    // a[0] = (3);
    // a[1] = (6);
    // a[2] = (2);
    // a[3] = (5);
    // a[4] = (10);
    // a[5] = (9);

    
    mergeSort(1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
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

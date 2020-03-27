#include "bits/stdc++.h"
// https://code.google.com/codejam/contest/6214486/dashboard#s=p2
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int getNumber(int n, unsigned long long k)
{
    unsigned long long midLet = pow(2, n - 1);

    if (n == 1)
    {
        return 0;
    }
    if (k == midLet)
    {
        return 0;
    }
    if (k > midLet)
    {
        unsigned long long temp = (midLet - (k - midLet));
        return getNumber(n - 1, temp) ^ 1;
    }
    else
    {
        return getNumber(n - 1, k);
    }
}
int main()
{
    // unsigned long long a=1;
    // for (int i = 0; i < 64; i++)
    // {
    //    a=(a*2)+1;
    //    cout<<a<<" ";
    // }
    // unsigned long long aa=9223372036854775808;
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        unsigned long long x;
        cin >> x;
        cout << "Case #" << tt << ": "<< getNumber(64, x)<< "\n";
    }
    return 0;
}

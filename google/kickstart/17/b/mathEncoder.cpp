#include "bits/stdc++.h"
//https://code.google.com/codejam/contest/11304486/dashboard
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int main()
{
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    unsigned long long div=1000000007;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int x,curIndex=0;
        cin >> x;
        int pdata[x];
        unsigned long long sum=0;
        for (int i = 0; i < x; i++)
        {
            cin>>pdata[i];

            for (int j = 0; j < curIndex; j++)
            {
                sum+=(pdata[i]-pdata[j])*pow(2,curIndex-j-1);
                sum%=div;
            }
            curIndex++;   
        }
        
        cout << "Case #" << tt << ": "<<(sum)<< "\n";
    }
    return 0;
}

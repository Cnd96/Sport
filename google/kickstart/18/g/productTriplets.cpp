#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
long long solData[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n, a;
        long long res = 0,noZeros=0;
        cin >> n;
        unsigned long long pdata[n];
        vector<unsigned long long> tempData;
        memset(solData, 0, sizeof(solData));
        for (int i = 0; i < n; i++)
        {
            cin >> pdata[i];
        }
        sort(pdata, pdata + n);
        for (int i = 0; i < n; i++)
        {
            res += solData[pdata[i]];
            if(pdata[i] == 0) noZeros++;
            for (int j = 0; j < tempData.size(); j++)
            {
                unsigned long long temp = pdata[i] * tempData[j];
                if (temp < 200004)
                    solData[temp]++;
            }
            tempData.push_back(pdata[i]);
        }
        res+=(((noZeros)*(noZeros-1))/2)*(n-noZeros);
        cout << "Case #" << tt << ": " << res << "\n";
    }
    return 0;
}

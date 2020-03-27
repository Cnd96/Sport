#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n, a, temp, curH = 0;
        cin >> n;
        int pdata[n + 1];
        vector<int> solData;
        memset(pdata, 0, sizeof(pdata));

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            temp = min((n), a);
            for (int j = curH; j <= temp; j++)
            {
                pdata[j]++;
            }
            if (pdata[curH + 1] >= (curH + 1))
                curH++;
            solData.push_back(curH);
        }

        cout << "Case #" << tt << ": ";
        for (int i = 0; i < solData.size(); i++)
        {
            cout<<solData[i]<<" ";
        }
        
        cout << "\n";
    }
    return 0;
}

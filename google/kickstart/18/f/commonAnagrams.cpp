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
        int l, tot = 0;
        string a, b;
        cin >> l >> a >> b;
        vector<string> pdata;
        vector<string> sdata;

        for (int i = 0; i < l; i++)
        {
            for (int j = i; j < l; j++)
            {
                string temp = "";
                string temp2 = "";
                for (int k = i; k <= j; k++)
                {
                    temp.push_back(a[k]);
                    temp2.push_back(b[k]);
                }
                sort(temp.begin(), temp.end());
                sort(temp2.begin(), temp2.end());
                pdata.push_back(temp);
                sdata.push_back(temp2);
            }
        }

        for (int i = 0; i < pdata.size(); i++)
        {
            if (find(sdata.begin(), sdata.end(), pdata[i]) != sdata.end())
            {
                tot++;
            }
        }

        cout << "Case #" << tt << ": "<<tot<< "\n";
    }
    return 0;
}

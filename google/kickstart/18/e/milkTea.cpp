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
        int n, m, p;
        cin >> n >> m >> p;
        string arrn[n];
        string arrm[m];
        int sumone[p] = {0};
        int sumzer[p] = {0};
        vector<int> difarr;
        vector<int> mdifarr;
        vector<int> ptempdata;
        int currentSS = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arrn[i];
            for (int j = 0; j < p; j++)
            {
                if (arrn[i][j] == '0')
                    sumzer[j]++;
                else
                    sumone[j]++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arrm[i];
            int difTemp = 0;
            for (int j = 0; j < p; j++)
            {
                if (arrm[i][j] == '0')
                    difTemp += sumone[j];
                else
                    difTemp += sumzer[j];
            }
            mdifarr.push_back(difTemp);
        }

        for (int i = 0; i < p; i++)
        {
            if (sumone[i] > sumzer[i])
                currentSS += sumzer[i];
            else
                currentSS += sumone[i];

            difarr.push_back(abs(sumone[i] - sumzer[i]));
        }
        sort(mdifarr.begin(), mdifarr.end());
        if (mdifarr[0] != currentSS)
        {
            cout << "Case #" << tt << ": " << currentSS << "\n";
        }
        else
        {
            for (int j = 0; j < difarr.size(); j++)
            {
                int tempSize = ptempdata.size();
                for (int k = 0; k < tempSize; k++)
                {
                    if (m < tempSize)
                    {
                        if ((difarr[j] + ptempdata[k]) <= ptempdata[m - 1])
                        {
                            ptempdata.push_back(((difarr[j] + ptempdata[k])));
                        }
                    }
                    else
                    {
                        ptempdata.push_back(((difarr[j] + ptempdata[k])));
                    }
                }
                if (m < ptempdata.size())
                {
                    if ((difarr[j]) <= ptempdata[m - 1])
                    {
                        ptempdata.push_back((difarr[j]));
                    }
                }
                else
                {
                    ptempdata.push_back(difarr[j]);
                }
                sort(ptempdata.begin(), ptempdata.end());
            }

            sort(ptempdata.begin(), ptempdata.end());
            int res;
            for (int i = 0; i < ptempdata.size(); i++)
            {
                if (mdifarr.size() <= (i + 1))
                {
                    cout << "Case #" << tt << ": " << currentSS + ptempdata[i] << "\n";
                    break;
                }
                else if (mdifarr[1 + i] != (ptempdata[i] + currentSS))
                {
                    cout << "Case #" << tt << ": " << currentSS + ptempdata[i] << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}

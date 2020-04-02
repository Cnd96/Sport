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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<unsigned long long> vec;

        vec.push_back(0);
        vec.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            vector<unsigned long long> tempVec;
            tempVec.push_back(0);
            for (int j = 1; j < vec.size(); j++)
            {
                if (((arr[i] * 6) >= vec[j - 1]) && ((vec[j - 1] + arr[i]) < vec[j]))
                {
                    tempVec.push_back(vec[j - 1] + arr[i]);
                }
                else
                {
                    tempVec.push_back(vec[j]);
                }
            }
            if ((arr[i] * 6) >= vec[vec.size() - 1])
            {
                tempVec.push_back(vec[vec.size() - 1] + arr[i]);
            }
            vec.swap(tempVec);
        }

        cout << "Case #" << tt << ": "<<vec.size()-1<< "\n";
    }
    return 0;
}


// 4
// 2
// 9 1
// 3
// 8 4 100
// 9
// 10 10 10 100 100 10 10 10 100
// 6
// 10 3 2 3 2 4
#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int arr[] = {10, 3, 2, 3, 2, 4};
    int n = 6;
    vector<long long> vec;

    vec.push_back(0);
    vec.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        vector<long long> tempVec;
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

    for (int j = 0; j < vec.size(); j++)
    {
        cout << vec[j] << " ";
    }

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // int t;
    // cin >> t;
    // for (int tt = 1; tt <= t; tt++)
    // {
    //       cout << "Case #" << tt << ": " << "\n";
    // }
    return 0;
}

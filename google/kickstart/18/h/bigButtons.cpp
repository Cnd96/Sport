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
        int n, p;
        cin >> n >> p;
        string arr[p];
        bool arrB[p];
        memset(arrB, true, sizeof(arrB));

        for (int i = 0; i < p; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + p);
        unsigned long long minusSum = 0;
        for (int i = 0; i < p; i++)
        {
            if (arrB[i] == false)
                continue;
            for (int j = i + 1; j < p; j++)
            {
                if (arr[j].rfind(arr[i], 0) == 0)
                {
                    arrB[j] = false;
                }
            }
            if (arrB[i])
            {
                minusSum += pow(2, n - arr[i].length());
            }
        }
        unsigned long long aa = pow(2, n);
        cout << "Case #" << tt << ": " << (aa - minusSum) << "\n";
    }
    return 0;
}

#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int aa[5000000];
int main()
{
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        memset(aa, 0, sizeof(aa));
        int n, r;
        long long maxScore = 0;
        long long prevScore;
        string s;
        cin >> n >> s;
        r = n / 2;
        if (n % 2 == 1)
            r++;
        for (int i = 0; i < n; i++)
        {
            aa[i] = s[i] - '0';
        }

        for (int i = 0; i < r; i++)
        {
            maxScore += aa[i];
        }
        prevScore=maxScore;
        for (int i = r; i < n; i++)
        {
            prevScore=(prevScore-aa[i-r])+aa[i];
            maxScore=max(prevScore,maxScore);
        }
        cout << "Case #" << tt << ": " << maxScore << endl;
    }
    return 0;
}

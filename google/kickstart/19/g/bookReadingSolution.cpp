#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define lim 100005
int main()
{
    int pageData[lim] ;
    bool pageTornData[lim];
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n, m, q, tornPage, pageR;
        cin >> n >> m >> q;
        memset(pageData, 0, sizeof(pageData));
        memset(pageTornData, false, sizeof(pageTornData)); 
        
        for (int j = 0; j < m; j++)
        {
            cin >> tornPage;
            pageTornData[tornPage] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            int div = 1;
            int inc = 1;
            while (true)
            {
                div = i * inc;
                if (div > n)
                {
                    break;
                }
                else
                {
                    if (!pageTornData[div])
                    {
                        pageData[i]++;
                    }
                    inc++;
                }
            }
        }
        long long totalPages = 0;
        for (int j = 0; j < q; j++)
        {
            cin >> pageR;
            totalPages += pageData[pageR];
        }
        cout << "Case #" << tt << ": " << totalPages << endl;
    }
    return 0;
}
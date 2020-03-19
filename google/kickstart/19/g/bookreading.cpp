#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define lim 100001
int getIntersection(vector<int> arr1, vector<int> arr2, int m, int n)
{
    int i = 0, j = 0, noMatches = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            noMatches++;
            i++;
            j++;
        }
    }
    return noMatches;
}

int main()
{

    vector<int> odata[lim];
    for (int i = 1; i < lim; i++)
    {
        int div = 1;
        int inc = 1;
        while (true)
        {
            div = i * inc;
            if (div > lim)
            {
                break;
            }
            else
            {
                odata[i].push_back(div);
                inc++;
            }
        }
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m, q, tornPage, noPages;
        int totalPages = 0;
        vector<int> goodPageNmubers;
        int currentPage = 1;
        cin >> n >> m >> q;
        int qArr[q];
        for (int j = 0; j < m; j++)
        {
            cin >> tornPage;
            while (currentPage < tornPage)
            {
                goodPageNmubers.push_back(currentPage);
                currentPage++;
            }
            currentPage++;
        }
        for (int j = 0; j < q; j++)
        {
            cin >> qArr[j];
        }
        sort(qArr, qArr + q);
        while (currentPage <= n)
        {
            goodPageNmubers.push_back(currentPage);
            currentPage++;
        }
        if (goodPageNmubers.size() == 0)
        {
            cout << "Case #" << i << ": 0" << endl;
        }
        else
        {
            int prevQ = qArr[0];
            if(prevQ==1){
                noPages= goodPageNmubers.size();
            }
            else
            {
               noPages = getIntersection(goodPageNmubers, odata[qArr[0]], goodPageNmubers.size(), odata[qArr[0]].size());
            }
            
            totalPages += noPages;
            for (int j = 1; j < q; j++)
            {
                if (prevQ == qArr[j])
                {
                    totalPages += noPages;
                }
                else
                {
                    noPages = getIntersection(goodPageNmubers, odata[qArr[j]], goodPageNmubers.size(), odata[qArr[j]].size());
                    totalPages += noPages;
                    prevQ= qArr[j];
                }
            }
            cout << "Case #" << i << ": " << totalPages << endl;
        }
    }
    return 0;
}
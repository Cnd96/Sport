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
        int N, K,currentDay=0,dayConsumption=0,totalConsumption=0;
        cin >> N >> K;
        vector<int> pData(N);
        for (int i = 0; i < N; i++)
        {
            cin >> pData[i];
        }
        sort(pData.begin(),pData.end());

        while (pData.size()!=0)
        {
            if((currentDay<pData[0])&&(dayConsumption<K)){
                totalConsumption++;
                dayConsumption++;
            }

            if(dayConsumption==K){
                dayConsumption=0;
                currentDay++;
            }
            pData.erase(pData.begin());
            /* code */
        }
        
        

        cout << "Case #" << tt << ": "<<totalConsumption<< "\n";
       
    }
    return 0;
}
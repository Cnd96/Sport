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
        int n, m,iniSum=0,res=INT_MAX;
        cin >> n >> m;
        int arr[n];
        int arr2[n];
        for (int i = 0; i < n; i++)cin >> arr[i];
        
        sort(arr, arr + n);

        for (int i = 0; i < m-1; i++)
        {
            iniSum+=arr[i];
            arr2[i]=0;
        }
        arr2[m-2]=iniSum;
        for (int i = m-1; i < n; i++)
        {
            arr2[i]=arr2[i-1]+arr[i]-arr[i-(m-1)];
        }

        for (int i = m-1; i < n; i++)
        {
          res=min(res,arr[i]*(m-1)-arr2[i-1]);
        }
        cout << "Case #" << tt << ": "<<res<< "\n";
    }
    return 0;
}

  
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
        int m, n, a, b, c,maxi;
        cin>>m>>n;
        set<int> odata;
        for (int i = 0; i < m; i++)
        {
            cin >> a;
            if (__builtin_popcount(a) % 2 != 0)odata.insert(i);
        }
         cout << "Case #" << tt << ":" ;
        for (int i = 0; i < n; i++)
        {
            cin >> b >> c;
            odata.erase(b);
            if (__builtin_popcount(c) % 2 != 0)odata.insert(b);

            if(odata.size()%2==0){
               cout<<" "<<m;
            }
            else
            {
                auto it=prev(odata.end());
                maxi=*it;
                it=odata.begin();
                maxi=max(maxi,(m-1-*it));
                cout<<" "<<maxi;
            }
        }
        cout<<endl;
    }
    return 0;
}

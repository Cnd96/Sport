#include "bits/stdc++.h"
// https://code.google.com/codejam/contest/6214486/dashboard#s=p2
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
        string s, d,startp;
        map<string, string> map1;
        map<string, int> map2;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> s >> d;
            map1.insert({s, d});
            map2.insert({s, 0});
            map2.insert({d, 0});
        }

        for (auto itr = map1.begin(); itr != map1.end(); ++itr)
        {
            auto ii=map2.find( itr->second);
            ii->second++;
        }
        for (auto itr = map2.begin(); itr != map2.end(); ++itr)
        {
            if(itr->second==0)startp=itr->first;
        }
         cout << "Case #" << tt << ": ";
        while (1)
        {
             auto ii=map1.find(startp);

             if(ii!=map1.end()){
                 startp=ii->second;
                 cout<<ii->first<<"-"<<ii->second<<" ";
             }
             else
             {
                 break;
             }
        }
        cout<<'\n';
       
    }
    return 0;
}

#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int con=-1;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n,d;
        cin >> n;
        bool sold[n];
        int noApp[n];
        memset(sold, false, sizeof(sold));
        memset(noApp, 0, sizeof(noApp));
        for (int i = 0; i < n; i++)
        {
            cin>>d;
            if (d==0)cout<<con<<endl;
            else
            {
                int temp[d];
                for (int j = 0; j < d; j++)
                {
                    cin>>temp[j];
                    noApp[temp[j]]++;
                }
                int appTemp=INT_MAX;
                int res=-1;
                for (int j = 0; j < d; j++)
                {
                    if(!sold[temp[j]]){
                        if(noApp[temp[j]]<appTemp){
                            appTemp=noApp[temp[j]];
                            res=temp[j];
                        }
                    }
                }
                if(res>=0){
                    sold[res]=true;
                }
                cout<<res<<endl;
            }
        }
    }
    return 0;
}

#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    string str="abhu";
    int n = str.length();
    // cout<< (1 << n)<<" "<<n;
    for (int i = 1; i < (1 << n); i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            if ((i & 1 << j) != 0)
            {
                // append chars for set bit
                // s += str[j];
                cout<<j;
            }
        }
        cout<<endl;
    }
    return 0;
}

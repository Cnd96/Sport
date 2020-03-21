#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
unsigned long long a1;
unsigned long long a2;
unsigned long long b1;
unsigned long long b2;
int b33;
int main()
{
    // string ssss="145623456785623";
    // b33=stoull(ssss, nullptr, 10);
    // cout<<b33;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        bool isOdd = false;
        string s,s2,s4;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (((s[i] - '0') % 2 == 1))
            {
                isOdd = true;
                if (i == (s.size() - 1))
                {
                    cout << "Case #" << tt << ": 1" << endl;
                }
                else
                {
                    if ((s[i] - '0') == 9)
                    {
                        string s1(s.size() - (i + 1), '8');
                        s2 = s.substr(i);
                        s2[0] = '1';
                        a1=stoull(s2, nullptr, 10);
                        a2=stoull(s1, nullptr, 10);
                        cout << "Case #" << tt << ": " << a1 - a2 << endl;
                        break;
                    }
                    else
                    {
                        string s1(s.size() - i, '0');
                        s2 = s.substr(i);
                        s1[0] = '2';
                        s2[0] = '1';
                        a1=stoull(s1, nullptr, 10);
                        a2=stoull(s2, nullptr, 10);

                        string s3(s.size() - (i + 1), '8');
                        s4 = s.substr(i);
                        s4[0] = '1';
                        b1=stoull(s3, nullptr, 10);
                        b2=stoull(s4, nullptr, 10);
                        

                        cout <<"Case #" << tt << ": " << min((a1 - a2),(b2-b1)) << endl;
                        break;
                    }
                }
            }
        }
        if (!isOdd)
            cout << "Case #" << tt << ": 0" << endl;
    }
    return 0;
}


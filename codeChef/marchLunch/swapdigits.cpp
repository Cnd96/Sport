#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int concat(char a, char b)
{
    string s1 = string(1, a);
    string s2 = string(1, b);

    string s = s1 + s2;
    int c = stoi(s);
    return c;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int a, b;
        cin >> a >> b;

        int maxi = a + b;
        char oneone, twoone, maxONe, maxTWo, onetwo, twotwo;
        if (a < 10)
        {
            oneone = '0' + a;
        }
        else
        {
            int digitone = a % 10;
            int digitTwo = a / 10;
            onetwo = '0' + digitone;
            oneone = '0' + digitTwo;
        }
        if (b < 10)
        {
            twoone = '0' + b;
        }
        else
        {
            int digitone = b % 10;
            int digitTwo = b / 10;
            twotwo = '0' + digitone;
            twoone = '0' + digitTwo;
        }

        if (a < 10 && b < 10)
            ;
        else if (a < 10)
        {
            maxi = max(maxi, concat(oneone, twotwo) + concat('0', twoone));
            maxi = max(maxi, concat(twoone, oneone) + concat('0', twotwo));
        }
        else if (b < 10)
        {
            maxi = max(maxi, concat(twoone, onetwo) + concat('0', oneone));
            maxi = max(maxi, concat(oneone, twoone) + concat('0', onetwo));
        }
        else
        {
            maxi = max(maxi, concat(oneone, twotwo) + concat(twoone, onetwo));
            maxi = max(maxi, concat(oneone, twoone) + concat(onetwo, twotwo));
            maxi = max(maxi, concat(twoone, onetwo) + concat(oneone, twotwo));
            maxi = max(maxi, concat(twotwo, onetwo) + concat(twoone, oneone));

        }

        cout << maxi << "\n";
    }
    return 0;
}

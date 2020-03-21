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
        int N, Q, P, oddSum = 0, evenSum = 0;
        cin >> N >> Q;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            if (__builtin_popcount(A[i]) % 2 == 0)
            {
                evenSum++;
            }
            else
            {
                oddSum++;
            }
        }
        for (int i = 0; i < Q; i++)
        {
            cin >> P;
            if (__builtin_popcount(P)% 2 == 0)
            {
                cout << evenSum << " " << oddSum << "\n";
            }
            else
            {
                 cout << oddSum << " " << evenSum << "\n";
            }
        }
    }
    return 0;
}

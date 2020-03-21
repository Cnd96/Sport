#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int a[30];
int aa = 0;

ll mem[33][2][10];

ll go(int pos, int fl, int rem)
{
    if (pos == -1)
    {
        if (rem == 0) return 0;
        return 1;
    }
    if (mem[pos][fl][rem] != -1) return mem[pos][fl][rem];
    ll &ans = mem[pos][fl][rem];
    ans = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (fl == 1 && i > a[pos]) break;
        ans += go(pos - 1, fl && i == a[pos], (rem * 10 + i) % 9);
    }
    return ans;
}
    

ll solve(ll x)
{
    aa = 0;
    while (x)
    {
        a[aa++] = x % 10;
        x /= 10;
    }
    memset(mem, -1, sizeof mem);
    return go(aa - 1, 1, 0);
}


int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int tests;
    scanf("%d", &tests);
    forn(testid, tests)
    {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        ll res = solve(r) - solve(l) + 1;
        printf("Case #%d: %lld\n", testid + 1, res);
    }

    return 0;
}

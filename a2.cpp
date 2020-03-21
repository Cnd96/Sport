#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

ll po (ll b, ll p) {
    ll cur = 1;
    F0R(i,p) cur *= b;
    return cur;
}

ll get(ll ad, ll x) {
    ll ans = 0;
    if (x <= 9) {
        F0R(i,min(x+1,9LL)) if ((ad+i) % 9 != 0) ans ++;
        return ans;
    }
    
    string s = to_string(x);
    ans += (s[0]-'0')*po(9,sz(s)-2)*8;
    if (s[0] == '9') return ans;
    return get(ad+(s[0]-'0'),stoll(s.substr(1,sz(s)-1)))+ans;
}

void solve() {
    ll a,b; cin >> a >> b;
    cout << get(0,b)-get(0,a-1);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    // FOR(i,1,1000001) assert(get(i)-get(i-1) == ok(i));
    FOR(i,1,T+1) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
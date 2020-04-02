#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int
#define vi vector<int>
#define vii vector< vector<int> >
#define PI 3.1415926535897932384626433832795
#define INF 9223372036854775807LL

ll dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int TT = 1; TT <= T; TT++) {
		cout << "Case #" << TT << ": ";
		int n;
		cin >> n;
		vector<ll> w(n);
		for(int i = 0; i < n; i++) {
			cin >> w[i];
		}
		memset(dp,-1,sizeof(dp));
		dp[0] = INF;
		for(int i = n-1; i >= 0; i--) {
			for(int j = n-i; j >= 1; j--) {
				dp[j] = max(dp[j],min(dp[j-1]-w[i],6*w[i]));
			}
		}
		for(int i = n; i >= 1; i--) {
			if(dp[i] >= 0) {
				cout << i;
				break;
			}
		}
		cout << "\n";
	}
	return 0;
}


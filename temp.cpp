//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|10|2024 11:43:58            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int mod_mul(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a * b) % MOD) + MOD) % MOD;
}

int mod_add(int a, int b, int MOD = mod) {
    a = a % MOD, b = b % MOD;
    return (((a + b) % MOD) + MOD) % MOD;
}

int dp[100][100];

int possibleWay(int pair, int type) {
    if (pair == 0)
        return 1;
    if (pair == 1)
        return type;
    if (dp[pair][type] != -1)
        return dp[pair][type];
    int ans = 0;
    for (int i = 0; i < pair; i++) {
        // int tempPair1 = i, tempPair2 = pair - i - 1;
        ans = mod_add(ans, mod_mul(possibleWay(i, type),
                                   possibleWay(pair - i - 1, type)));
    }
    ans = mod_mul(ans, type);
    dbg(pair, type, ans);
    return ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int pair, type;
    cin >> pair >> type;
    // cout << possibleWay(pair, type) << endl;
    // bottom up
    for (int i = 0; i <= pair; i++) {
        for (int j = 0; j <= type; j++) {
            if (i == 0)
                dp[i][j] = 1;
            else if (i == 1)
                dp[i][j] = j;
            else {
				int ans = 0;
                for (int k = 0; k < i; k++) {
					ans += dp[k][j] * dp[i - k - 1][j];
                }
                dp[i][j] = ans * j;
            }
        }
    }
	for(int i = 0; i <= pair; i++) {
		for(int j = 0; j <= type; j++) {
			dbg(i, j, dp[i][j]);
		}
	}

    cout << dp[pair][type] % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
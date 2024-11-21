//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|11|2024 23:43:45            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] < n)
            mp[v[i]]++;
    }
    ll mex = 0;
    while(mp.count(mex))
        mex++;
    if(mex == 0){
        cout << 0 << "\n";
        return;
    }

    vector<vector<ll>> dp(mex, vector<ll>(mex + 1, 0));

    for (ll i = 0; i <= mex; i++)
        dp[0][i] = (mp[0] - 1) * i;
    for (ll i = 1; i < mex; i++) {
        for (ll j = 0; j <= mex; j++) {
            dp[i][j] = dp[i - 1][j];
            ll temp = (mp[i] - 1) * j + i + dp[i - 1][i];
            dp[i][j] = min(dp[i][j], temp);
        }
    }
    cout << dp[mex - 1][mex] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
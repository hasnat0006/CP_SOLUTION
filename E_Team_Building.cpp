//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|11|2024 00:43:42            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

const ll N = 1e5 + 5;
ll n, p, k;
vector<pair<ll, ll>> v;
vector<ll> position[N];
ll dp[N][1 << 8];

ll findMaxStrength(ll i, ll bitmask) {
    if (i == n)
        return 0;
    if (dp[i][bitmask] != -1)
        return dp[i][bitmask];

    // check is the maximum number of spectator is reached or not
    ll setBits = __builtin_popcount(bitmask);
    ll strength = findMaxStrength(i + 1, bitmask) + ((i - setBits < k) ? v[i].first : 0);

    if (setBits != p) {
        for (ll pos = 0; pos < p; pos++) {
            if (bitmask & (1 << pos))
                continue;
            strength = max(strength, position[v[i].second][pos] + findMaxStrength(i + 1, (bitmask | (1 << pos))));
        }
    }
    return dp[i][bitmask] = strength;
}

void solve() {
    cin >> n >> p >> k;
    v.resize(n);
    ll x;
    memset(dp, -1, sizeof(dp));
    for (ll i = 0; i < n; i++) {
        cin >> x;
        v[i] = {x, i};
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < p; j++) {
            cin >> x;
            position[i].push_back(x);
        }
    }
    sort(vr(v));
    cout << findMaxStrength(0, 0) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
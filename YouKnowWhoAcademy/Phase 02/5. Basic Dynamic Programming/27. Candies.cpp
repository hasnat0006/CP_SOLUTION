//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|10|2024 12:16:11            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

vector<ll> v;
ll dp[105][100005];

ll number_of_way(ll i, ll k) {
    if (k == 0)
        return 1;
    if (i == -1)
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    ll way = 0;
    for (ll give = 0; give <= min(k, v[i]); give++) {
        way = (way + number_of_way(i - 1, k - give)) % mod;
    }
    return dp[i][k] = way;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << number_of_way(n - 1, k) << '\n';
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
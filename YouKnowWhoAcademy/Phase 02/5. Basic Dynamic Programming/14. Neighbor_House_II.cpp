//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|10|2024 00:25:29            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

ll n;
vector<ll> v;
ll dp[1005][2];

ll find_max(ll i, ll last_taken = 0) {
    if (i < 0)
        return 0;
    if (dp[i][last_taken] != -1)
        return dp[i][last_taken];
    // nibo na
    ll ans1 = find_max(i - 1, last_taken), ans2 = 0;
    // nite parle nibo
    if (i == n - 1)
        ans2 = v[i] + find_max(i - 2, !last_taken);
    else if(i == 0 and last_taken == 0)
        ans2 = v[i] + find_max(i - 2, last_taken);
    else if(i != 0 and i != n - 1)
        ans2 = v[i] + find_max(i - 2, last_taken);
    return dp[i][last_taken] = max(ans1, ans2);
}

void solve() {
    cin >> n;
    v.resize(n);
    v.clear();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << find_max(n - 1) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
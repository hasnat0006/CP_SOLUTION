//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|10|2024 15:24:03            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

ll n, m, q, d;
vector<ll> v;
ll dp[205][250][15][2];

ll find_way(ll i, ll sum = 0, ll taken = 0) {
    if (sum % d == 0 and taken == m)
        return 1;
    if (i == -1)
        return 0;
    if (dp[i][abs(sum)][taken][sum > 0 ? 1 : 0] != -1)
        return dp[i][abs(sum)][taken][sum > 0 ? 1 : 0];
    ll ans = find_way(i - 1, sum, taken);
    if (taken < m)
        ans += find_way(i - 1, sum + v[i], taken + 1);
    return dp[i][abs(sum)][taken][sum > 0 ? 1 : 0] = ans;
}

void solve() {
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    while (q--) {
        memset(dp, -1, sizeof(dp));
        v.clear();
        v.resize(0);
        cin >> d >> m;
        if(m > n){
            cout << 0 << '\n';
            continue;
        }
        for (auto i : a)
            v.push_back(i % d);
        cout << find_way(n - 1) << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}
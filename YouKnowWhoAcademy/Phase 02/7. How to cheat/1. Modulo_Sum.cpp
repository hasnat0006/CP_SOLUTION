#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int dp[1005][1005][2];
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= m;
    }
    if (n >= m) {
        cout << "YES" << '\n';
        return;
    }
    memset(dp, -1, sizeof(dp));
    function<ll(ll, ll, ll)> yo = [&](ll i, ll sum, ll take) -> ll {
        if (i == n)
            return (sum == 0 and take);
        if (dp[i][sum][take] != -1)
            return dp[i][sum][take];
        dp[i][sum][take] = yo(i + 1, sum, take);
        dp[i][sum][take] |= yo(i + 1, (sum + v[i]) % m, 1);
        return dp[i][sum][take];
    };
    cout << (yo(0, 0, 0) ? "YES" : "NO") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
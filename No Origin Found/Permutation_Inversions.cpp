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

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> available;
    for (int i = min(n - 1, k - 1); i > 0; i--) {
        available.push_back(i);
    }
    ll an = available.size(), f = 0;
    vector<ll> way;
    dbg(available);
    vector<vector<ll>> dp(an + 5, vector<ll>(k + 5, -1));
    function<ll(ll, ll)> findway = [&](ll i, ll sum) -> ll {
        if (sum == 0)
            return 1;
        if (i == an)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        ll not_take = findway(i + 1, sum);
        ll take = 0;
        if (sum - available[i] >= 0) {
            take = findway(i + 1, sum - available[i]);
        }
        return dp[i][sum] = (take + not_take) % mod;
    };

    cout << (findway(0, k)) << '\n';
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
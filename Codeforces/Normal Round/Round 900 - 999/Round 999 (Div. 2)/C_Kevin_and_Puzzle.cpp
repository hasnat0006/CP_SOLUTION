#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 998244353;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<ll> dp(n, -1);

    function<ll(int)> findAns = [&](int i) -> ll {
        if (i >= n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        ll ans = 0;
        if (i == 0) {
            if (v[i] == 0)
                ans += findAns(i + 1), ans %= mod;
            if (i + 1 < n) {
                if (v[i + 1] == 1)
                    ans += findAns(i + 2), ans %= mod;
            }
            else
                ans += findAns(i + 2), ans %= mod;
        }
        else {
            if (v[i - 1] == v[i])
                ans += findAns(i + 1), ans %= mod;
            if (i + 1 < n) {
                if (v[i + 1] - v[i - 1] == 1)
                    ans += findAns(i + 2), ans %= mod;
            }
            else
                ans += findAns(i + 2), ans %= mod;
        }
        return dp[i] = ans;
    };
    cout << findAns(0) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
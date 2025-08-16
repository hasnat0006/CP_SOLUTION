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
ll dp[51][51][2][2501];

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    function<ll(ll, ll, ll, ll)> findAns = [&](ll i, ll taken, ll takenOrNot,
                                               ll sum) -> ll {
        if (dp[i][taken][takenOrNot][sum] != -1)
            return dp[i][taken][takenOrNot][sum];
        ll ans = (takenOrNot and taken > 0 and sum / taken == k and
                  sum % taken == 0);
        if (i == n)
            return ans;
        ans += findAns(i + 1, taken, 0, sum);
        ans += findAns(i + 1, taken + 1, 1, sum + v[i]);
        return dp[i][taken][takenOrNot][sum] = ans;
    };

    cout << findAns(0, 0, 0, 0) << '\n';
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
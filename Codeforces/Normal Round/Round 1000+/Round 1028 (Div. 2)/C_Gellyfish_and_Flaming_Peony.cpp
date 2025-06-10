#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(vf(v));
    ll cnt = 0, gcd = 0;
    for (int i = 0; i < n; i++) {
        gcd = __gcd(gcd, v[i]);
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == gcd) {
            cnt++;
        }
    }
    if (cnt > 0) {
        cout << n - cnt << '\n';
        return;
    }
    vector<ll> dp(5005, inf);
    queue<ll> q;
    for (auto i : v) {
        dp[i] = 0;
        q.push(i);
    }
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            ll g = __gcd(x, v[i]);
            if (dp[g] == inf) {
                dp[g] = dp[x] + 1;
                q.push(g);
            }
        }
    }
    cout << dp[gcd] + n - 1 << '\n';
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
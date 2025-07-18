//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|05|2025 21:57:24            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 5), b(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll mx = *max_element(vf(a));
    vector<ll> change[mx + 5];
    for (int i = 1; i <= n; i++) {
        ll temp = a[i];
        while (temp >= 1) {
            ll pre = a[i] - 1;
            ll div = pre / temp + 1;
            ll l = pre / div + 1;
            change[l].push_back(i);
            temp = l - 1;
        }
    }

    b = a;

    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += max(0, a[i] - a[i - 1]);
    cout << ans << " ";

    for (int k = 2; k <= mx; k++) {
        for (auto &id : change[k]) {
            int prev = (a[id - 1] + k - 1) / k;
            int cur = (a[id] + k - 1) / k;
            int next = (a[id + 1] + k - 1) / k;

            ans -= max(0, b[id] - b[id - 1]);
            ans += max(0, cur - b[id - 1]);

            ans -= max(0, b[id + 1] - b[id]);
            ans += max(0, b[id + 1] - cur);

            b[id] = cur;
        }
        cout << ans << " ";
    }
    cout << "\n";
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
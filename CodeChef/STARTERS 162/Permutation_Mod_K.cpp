//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|11|2024 21:04:44            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> m(n), ans(n);
    for (int i = 1; i <= n; i++) {
        m[i - 1] = i % k;
        ans[i - 1] = i;
    }
    bool isOk = false;
    for (int cholbe = 0; cholbe < n; cholbe++) {
        // jodi ok thale taile eitai ans
        ll f = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] % k == m[i]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            isOk = true;
            break;
        }
        else {
            ll store = ans.front();
            ans.erase(ans.begin());
            ans.push_back(store);
        }
    }
    if (isOk) {
        for (auto i : ans)
            cout << i << ' ';
        cout << '\n';
    }
    else
        cout << -1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
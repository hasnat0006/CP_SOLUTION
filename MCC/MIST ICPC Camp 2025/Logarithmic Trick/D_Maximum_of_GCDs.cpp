#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename p, typename q>
using ht = gp_hash_table<p, q>;

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> ans(n + 1);
    vector<pair<ll, ll>> st[n + 1];
    for (int i = 1; i <= n; i++) {
        for (auto [g, l] : st[i - 1]) {
            ll ng = gcd(v[i], g);
            ans[l + 1] = max(ans[l + 1], ng);
            if (st[i].empty() or st[i].back().first != ng)
                st[i].push_back({ng, l + 1});
            else
                st[i].back().second = max(st[i].back().second, l + 1);
        }
        ans[1] = max(ans[1], v[i]);
        if (st[i].empty() or st[i].back().first != v[i])
            st[i].push_back({v[i], 1});
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
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
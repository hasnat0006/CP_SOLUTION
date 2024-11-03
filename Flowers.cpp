//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|11|2024 16:18:44            !//
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag,
                     tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                        tree_order_statistics_node_update>;
template <typename T>
using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> height(n), beauty(n);
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < n; i++) {
        cin >> height[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> beauty[i];
    }
    dbg(height);
    dbg(beauty);
    o_set<ll> st;
    vector<ll> start(n + 1);
    iota(vf(start), 0);
    dbg(start);
    for (int i = 0; i < n; i++) {
        ll h = height[i], sum = 0;
        ll a = 0, b = 0;
        for (int k = min(2, (int)st.size()); k > 0; k--) {
            int id = st.order_of_key(start[h] - 1);
            a = *st.find_by_order(id);
            dbg(h, start[h], id, a);
            if (dp[a] + beauty[i] > dp[h]) {
                dp[h] = dp[a] + beauty[i];
                start[h] = start[a];
                // dbg(start[h]);
            }
        }
        st.insert(h);
        dp[h] = max(dp[h], beauty[i]);
        start[h] = min(h, start[h]);
        dbg(start[h], dp[h]);
        dbg("----", dp[h]);
    }
    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << '\n';
    cout << *max_element(dp, dp + n + 1) << '\n';
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
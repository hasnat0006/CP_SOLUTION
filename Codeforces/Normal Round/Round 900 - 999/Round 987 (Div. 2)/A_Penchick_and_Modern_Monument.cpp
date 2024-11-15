//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|11|2024 00:34:53            !//
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

void solve() {
    ll n;
    cin >> n;
    o_multiset<ll> st;
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll temp = st.order_of_key(x + 1);
        ans = min(ans, n - 1 - temp);
        // dbgc(x, temp);
        st.insert(x);
    }
    cout << ans << '\n';
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
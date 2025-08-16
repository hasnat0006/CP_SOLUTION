#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);
    o_set<pair<ll, ll>> st;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        st.insert({v[i], i});
    };
    while (m--) {
        char type;
        cin >> type;
        if (type == '?') {
            ll l, r;
            cin >> l >> r;
            cout << st.order_of_key({r, inf}) - st.order_of_key({l, 0}) << '\n';
        }
        else {
            ll id, val;
            cin >> id >> val;
            st.erase(st.find({v[id], id}));
            st.insert({val, id});
            v[id] = val;
        }
    }
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
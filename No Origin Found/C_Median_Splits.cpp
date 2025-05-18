#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
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

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<ll> pre(n), suf(n);
    o_set<pair<ll, ll>> s1, s2;
    for (int i = 0; i < n; i++) {
        s1.insert({v[i], i});
        s2.insert({v[n - i - 1], n - i - 1});
        // median of first i elements
        ll x = i + 1;
        auto it = s1.find_by_order(((x) % 2 == 0 ? x / 2 - 1 : x / 2));
        pre[i] = it->first;
        // median of last xelements
        auto it2 = s2.find_by_order(((x) % 2 == 0 ? x / 2 - 1 : x / 2));
        suf[n - i - 1] = it2->first;
        dbg(i, s1, s2);
    }
    dbg(pre);
    dbg(suf);
    for(int i = 1; i < n - 2; i++) {
        ll a = pre[i - 1], b = suf[i + 2], c = min(v[i], v[i + 1]);
        vector<ll> x = {a, b, c};
        sort(vf(x));
        if(x[1] <= k) {
            cout << "YES" << endl;
            dbg(i, a, b, c);
            return;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        ll a = pre[i - 1], b = suf[i + 1], c = v[i];
        vector<ll> x = {a, b, c};
        sort(vf(x));
        if (x[1] <= k) {
            cout << "YES" << endl;
            dbg(i, a, b, c);
            return;
        }
    }
    cout << "NO" << endl;
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
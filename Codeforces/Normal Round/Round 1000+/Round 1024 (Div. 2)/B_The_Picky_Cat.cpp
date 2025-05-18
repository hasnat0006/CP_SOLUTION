#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
    ll n;
    cin >> n;
    o_set<pair<ll, ll>> s;
    ll f = 0, need;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (!f)
            need = abs(x), f = 1;
        s.insert({abs(x), i});
    }
    ll need_index = (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        // need_index element
        auto it = *s.find_by_order(need_index);
        dbg(it, need);
        if (abs(it.first) == need) {
            cout << "YES" << '\n';
            return;
        }
        // take the last element
        auto l = *s.rbegin();
        s.insert({-l.first, l.second});
        s.erase(s.find(l));
        dbg(s);
    }
    cout << "NO" << '\n';
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
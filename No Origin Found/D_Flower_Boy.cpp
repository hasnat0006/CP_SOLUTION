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
using namespace std;
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    o_set<pair<ll, ll>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<ll> index(m, 0);
    for(int i = 0; i < m; i++) {
        // index of that element in s which has a value greater than or equal to b[i]
        auto it = s.lower_bound({b[i], -1});
        if(it == s.end())
            index[i] = -1;
        else {
            // erase till it
            // beginning iterator of s;
            auto it2 = s.begin();
            while(s.size() and it2 != it) {
                s.erase(it2);
                it2 = s.begin();
            }
            index[i] = it->second;
            s.erase(it);
        }
    }
    dbg(index);
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
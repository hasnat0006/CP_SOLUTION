//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|11|2024 09:09:55            !//
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

ll n, k;
vector<ll> a;
set<vector<int>> s;

void f(int i, vector<int> &v) {
    if (i == 0) {
        s.insert(v);
        return;
    }
    for (int num = 1; num <= k; num++) {
        v.push_back(num);
        f(i - 1, v);
        v.pop_back();
    }
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (ll &i : a)
        cin >> i;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zero++;
        }
    }
    vector<int> v;
    f(zero, v);
    int ans = 0;
    for (auto it : s) {
        o_multiset<int> o;
        int possible_ans = 0;
        for (int i = 0; i < n; i++) {
            // find the number of elements greater than a[i]
            int x = a[i];
            if (x == 0) {
                x = it.back();
                it.pop_back();
            }
            int cnt = o.order_of_key(x + 1);
            possible_ans += (o.size() - cnt);
            o.insert(x);
        }
        dbgc(possible_ans);
        ans = max(ans, possible_ans);
    }
    cout << ans << '\n';
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
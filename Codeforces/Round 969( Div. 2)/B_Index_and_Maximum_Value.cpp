//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|08|2024 20:55:14            !//
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

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(vf(a));
    o_set<int> s;
    for (auto i : a)
        s.insert(i);

    for (int i = 0; i < m; i++) {
        char c;
        dbg(s);
        int x, y;
        cin >> c >> x >> y;
        int idx = s.order_of_key(y + 1);
        dbg(idx, s.size(), y);
        if (idx == s.size()) {
            int val = *s.rbegin();
            if (val >= x) {
                s.erase(*s.rbegin());
                if (c == '+')
                    s.insert(val + 1);
                else
                    s.insert(val - 1);
            }
            cout << *s.rbegin() << " ";
        }
        else {
            if (idx != 0) {
                int val = *s.find_by_order(idx - 1);
                dbg(val);
                s.erase(s.find(val));
                if (c == '+')
                    s.insert(val + 1);
                else
                    s.insert(val - 1);
            }
            cout << *s.rbegin() << " ";
        }
    }
    cout << endl;
}

/*
[ s ] = [ {1,2,3} ]
[ idx, s.size(), y ] = [ 3, 3, 3 ]
[ s ] = [ {1,2,4} ]
[ idx, s.size(), y ] = [ 2, 3, 3 ]
[ s ] = [ {1,4} ]
[ idx, s.size(), y ] = [ 1, 2, 2 ]
[ s ] = [ {2,4} ]
[ idx, s.size(), y ] = [ 2, 2, 4 ]
[ s ] = [ {2,5} ]
[ idx, s.size(), y ] = [ 2, 2, 8 ]
*/

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
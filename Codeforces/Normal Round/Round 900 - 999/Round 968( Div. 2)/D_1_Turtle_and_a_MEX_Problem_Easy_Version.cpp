//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|08|2024 22:10:10            !//
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

/*
5 1919810
1 2 - 0
2 324003 0 -1
3 1416324 2 1460728 - 0
4 1312631 2 0 1415195 - 1
5 1223554 192248 2 1492515 725556 - 0
*/

void solve() {
    int n, m;
    cin >> n >> m;
    auto findMEX = [&](o_set<int> x) {
        // dbg(x);
        int mex = 0;
        int N = x.size();
        for (int i = 0; i <= N; i++) {
            if (x.find(i) == x.end()) {
                mex = i;
                break;
            }
        }
        return mex;
    };
    vector<o_set<int>> v(n);
    o_set<int> MEX;
    vector<int> StoreM;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        o_set<int> set;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            set.insert(y);
        }
        // dbg("input", set);
        int mex = findMEX(set);
        MEX.insert(mex);
        set.insert(mex);
        StoreM.push_back(mex);
        v[i] = set;
    }
    dbg(MEX);
    int mex = findMEX(MEX);
    MEX.insert(mex);
    dbg(v);
    dbg(StoreM);
    dbg(mex);
    // mex = findMEX(MEX);
    for (int i = 0; i < n; i++) {
        dbg(mex, StoreM[i]);
        if(mex < StoreM[i])
            continue;
        v[i].insert(mex);
        dbg(v[i]);
        int tempMex = findMEX(v[i]);
        v[i].erase(mex);
        if (tempMex > mex) {
            mex = tempMex;
        }
        dbg(tempMex, mex);
    }
    dbg(MEX);
    dbg("----");
    auto sumtillN = [&](int x) { return (x * (x + 1)) / 2; };

    int ans = sumtillN(m);
    dbg(ans, mex);
    mex = min(mex, m);
    cout << ans + (sumtillN(mex)) << endl;
}

// 1919810

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
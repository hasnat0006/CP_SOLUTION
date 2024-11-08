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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> st[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x--) {
            int y;
            cin >> y;
            st[i].insert(y);
        }
        dbg(st[i]);
    }

    vector<int> mex(n);

    auto findMex = [&](int id, int cur) {
        dbg("in", st[id]);
        while (st[id].count(cur)) {
            st[id].erase(st[id].find(cur));
            cur++;
        }
        dbg("out", st[id]);
        return cur;
    };

    for (int i = 0; i < n; i++)
        mex[i] = findMex(i, 1);

    dbg(mex);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if ((int)st[x].size() < (int)st[y].size()) {
                st[x].swap(st[y]);
                swap(mex[x], mex[y]);
            }
            for (auto &it : st[y])
                st[x].insert(it);
            st[y].clear();
            mex[x] = findMex(x, max(mex[x], mex[y]));
            mex[y] = 0;
        }
        else if (type == 2) {
            int x;
            cin >> x;
            x--;
            if (st[x].empty())
                cout << "complete" << '\n';
            else
                cout << mex[x] << '\n';
        }
        dbg(mex);
    }
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
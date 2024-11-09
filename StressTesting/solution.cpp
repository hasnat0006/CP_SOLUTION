//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|11|2024 00:34:53            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

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
    }

    vector<int> mex(n);

    auto findMex = [&](int id, int cur) {
        while (st[id].count(cur))
            cur++;
        return cur;
    };

    for (int i = 0; i < n; i++)
        mex[i] = findMex(i, 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if ((int)st[y].size() >= (int)st[x].size()) {
                st[x].swap(st[y]);
                swap(mex[x], mex[y]);
            }
            for (auto &it : st[y])
                st[x].insert(it);
            st[y].clear();
            mex[x] = findMex(x, max(mex[x], mex[y]));
        }
        else if (type == 2) {
            int x;
            cin >> x;
            x--;
            if (mex[x] == st[x].size() + 1)
                cout << "complete" << '\n';
            else
                cout << mex[x] << '\n';
        }
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
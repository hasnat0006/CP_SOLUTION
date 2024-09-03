//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|09|2024 01:22:57            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

class SEGMENT_TREE {
   public:
    vector<int> v;
    vector<int> seg;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array);
    void build(int ti, int low, int high) {
        if (low == high) {
            seg[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = (seg[2 * ti] + seg[2 * ti + 1]);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array),
    //! (ql & qr) = user input in 1 based indexing;
    int find(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return 0;
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        int l = find(2 * ti, tl, mid, ql, qr);
        int r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return (l + r);
    }
    //! intially: ti = 1, tl = 1, tr = n(number of elements in the array), id =
    //! user input in 1 based indexing, val = updated value;
    void update(int ti, int tl, int tr, int id, int val) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            seg[ti] = val;
            return;
        }
        int mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val);
        update(2 * ti + 1, mid + 1, tr, id, val);
        seg[ti] = (seg[2 * ti] + seg[2 * ti + 1]);
    }

};

void solve() {
    int n, q;
    cin >> n >> q;
    SEGMENT_TREE s(n);
    for (int i = 1; i <= n; i++) {
        cin >> s.v[i];
    }
    s.build(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            x++;
            cout << s.find(1, 1, n, x, x) << endl;
            s.update(1, 1, n, x, 0);
        }
        else if (type == 2) {
            int l, r;
            cin >> l >> r;
            l++;
            int x = s.find(1, 1, n, l, l);
            int val = x + r;
            s.update(1, 1, n, l, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            l++, r++;
            cout  << s.find(1, 1, n, l, r) << endl;
        }
        // s.indeedPrint(n);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
}
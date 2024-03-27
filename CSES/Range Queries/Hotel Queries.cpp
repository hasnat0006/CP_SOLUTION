//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|03|2024 22:08:57            !//
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

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

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
        seg[ti] = max(seg[2 * ti], seg[2 * ti + 1]);
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
        return max(l, r);
    }
    //! intially: ti = 1, tl = 1, tr = n(number of elements in the array), id =
    //! user input in 1 based indexing, val = updated value;
    void update(int ti, int tl, int tr, int id, int val) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            seg[ti] -= val;
            return;
        }
        int mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val);
        update(2 * ti + 1, mid + 1, tr, id, val);
        seg[ti] = max(seg[2 * ti], seg[2 * ti + 1]);
    }
    // use 1 based indexing for input and queries and update;
};

void solve() {
    int n, q;
    cin >> n >> q;
    SEGMENT_TREE s(n);
    for (int i = 1; i <= n; i++) {
        cin >> s.v[i];
    }
    s.build(1, 1, n);
    for (int i = 0; i < q; i++) {
        int mx = s.find(1, 1, n, 1, n);
        int x;
        cin >> x;
        if (x > mx) {
            cout << 0 << " ";
            continue;
        }
        int low = 1, high = n, ti = 1;
        dbg(ti, low, high);
        while (low != high) {
            int leftId = 2 * ti, rightId = 2 * ti + 1;
            int mid = (low + high) / 2;
            if (s.seg[leftId] >= x) {
                high = mid;
                ti = leftId;
            }
            else {
                low = mid + 1;
                ti = rightId;
            }
            dbg(ti, low, high);
        }
        cout << low << " ";
        s.update(1, 1, n, low, x);
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
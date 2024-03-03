//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|03|2024 18:42:37            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

class SegmentTree {
   public:
    int sz = 2e5 + 5;
    vector<int> v, seg;
    SegmentTree(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    void build(int ti, int low, int high) {
        if (high == low) {
            seg[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti + 1, low, mid);
        build(2 * ti + 2, mid + 1, high);
        seg[ti] = max(seg[2 * ti + 1], seg[ti * 2 + 2]);
    }
    int find(int tl, int tr, int ql, int qr, int ti) {
        if (tl > qr or tr < ql)
            return -inf;
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        int l = find(tl, mid, ql, qr, 2 * ti + 1);
        int r = find(mid + 1, tr, ql, qr, 2 * ti + 2);
        return (max(l, r));
    }
    void update(int ti, int low, int high, int id, int val) {
        if (id > high or id < low)
            return;
        if (id == high and high == low) {
            seg[ti] = val;
            return;
        }
        int mid = (low + high) / 2;
        update(2 * ti + 1, low, mid, id, val);
        update(2 * ti + 2, mid + 1, high, id, val);
        seg[ti] = max(seg[2 * ti + 1], seg[ti * 2 + 2]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        cin >> st.v[i];
    }
    st.build(0, 0, n - 1);
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            st.update(0, 0, n - 1, a - 1, b);
        }
        else {
            cout << st.find(0, n - 1, a - 1, b - 1, 0) << endl;
        }
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
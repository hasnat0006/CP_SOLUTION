//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 01:55:47            !//
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

class SEGMENT_TREE {
   public:
    vector<int> v;
    vector<int> seg;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    void build(int ti, int low, int high) {
        if (low == high) {
            seg[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = min(seg[2 * ti], seg[2 * ti + 1]);
    }
    int find(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return inf;
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        int l = find(2 * ti, tl, mid, ql, qr);
        int r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return min(l, r);
    }
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
        seg[ti] = min(seg[2 * ti], seg[2 * ti + 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SEGMENT_TREE seg(n);
    for (int i = 1; i <= n; i++)
        cin >> seg.v[i];
    seg.build(1, 1, n);
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
            seg.update(1, 1, n, l, r);
        else
            cout << seg.find(1, 1, n, l, r) << endl;
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
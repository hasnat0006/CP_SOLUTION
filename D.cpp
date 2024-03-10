//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|03|2024 00:26:50            !//
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
    void build(int ti, int low, int high, int cnt = 0) {
        if (low == high) {
            seg[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid, cnt + 1);
        build(2 * ti + 1, mid + 1, high, cnt + 1);
        cnt % 2 ? seg[ti] = (seg[2 * ti] | seg[2 * ti + 1]) : seg[ti] = (seg[2 * ti] ^ seg[2 * ti + 1]);
    }
    int find(int ti, int tl, int tr, int ql, int qr, int cnt = 0) {
        if (tl > qr || tr < ql) 
            return 0;
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        int l = find(2 * ti, tl, mid, ql, qr, cnt + 1);
        int r = find(2 * ti + 1, mid + 1, tr, ql, qr, cnt + 1);
        return cnt % 2 ? (l | r) : (l ^ r);
    }
    void update(int ti, int tl, int tr, int id, int val, int cnt = 0) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            seg[ti] = val;
            return;
        }
        int mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val, cnt + 1);
        update(2 * ti + 1, mid + 1, tr, id, val, cnt + 1);
        seg[ti] = cnt % 2 ? (seg[2 * ti] | seg[2 * ti + 1]) : (seg[2 * ti] ^ seg[2 * ti + 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    int preN = n;
    n = (1 << n);
    SEGMENT_TREE st(n);
    for (int i = 1; i <= n; i++)
        cin >> st.v[i];
    preN % 2 ? st.build(1, 1, n, 1) : st.build(1, 1, n, 0);
    while (q--) {
        int id, val;
        cin >> id >> val;
        preN % 2 ? st.update(1, 1, n, id, val, 1) : st.update(1, 1, n, id, val, 0);
        cout << st.seg[1] << endl;
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
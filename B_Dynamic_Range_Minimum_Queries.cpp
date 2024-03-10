//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|03|2024 00:03:00            !//
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
    vector<int> sum, mn;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        sum.resize(4 * n + 5);
        mn.resize(4 * n + 5);
    }
    void build(int ti, int low, int high) {
        if (low == high) {
            sum[ti] = mn[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        sum[ti] = (sum[2 * ti] + sum[2 * ti + 1]);
        mn[ti] = min(mn[2 * ti], mn[2 * ti + 1]);
    }
    int findSum(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return 0;
        }
        if (tl >= ql and tr <= qr)
            return sum[ti];
        int mid = (tl + tr) / 2;
        int l = findSum(2 * ti, tl, mid, ql, qr);
        int r = findSum(2 * ti + 1, mid + 1, tr, ql, qr);
        return (l + r);
    }
    int findMin(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return inf;
        }
        if (tl >= ql and tr <= qr)
            return mn[ti];
        int mid = (tl + tr) / 2;
        int l = findMin(2 * ti, tl, mid, ql, qr);
        int r = findMin(2 * ti + 1, mid + 1, tr, ql, qr);
        return min(l, r);
    }
    void update(int ti, int tl, int tr, int id, int val) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            sum[ti] = mn[ti] = val;
            return;
        }
        int mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val);
        update(2 * ti + 1, mid + 1, tr, id, val);
        sum[ti] = (sum[2 * ti] + sum[2 * ti + 1]);
        mn[ti] = min(mn[2 * ti], mn[2 * ti + 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SEGMENT_TREE sum(n);
    for (int i = 1; i <= n; i++) {
        cin >> sum.v[i];
    }
    sum.build(1, 1, n);
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            sum.update(1, 1, n, a, b);
        }
        else {
            cout << sum.findSum(1, 1, n, a, b) - sum.findMin(1, 1, n, a, b) << endl;
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
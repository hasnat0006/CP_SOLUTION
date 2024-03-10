//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|03|2024 11:10:27            !//
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

struct Node {
    int mx = 0, smx = 0, cntmx = 0, cntsmx = 0;
};

void printNode(Node &a) {
    cout << a.mx << " " << a.cntmx << " | " << a.smx << " " << a.cntsmx << endl;
}

Node pull(Node &a, Node &b) {
    map<int, int> mp;
    // printNode(a);
    // printNode(b);
    mp[a.mx] += a.cntmx;
    mp[a.smx] += a.cntsmx;
    mp[b.mx] += b.cntmx;
    mp[b.smx] += b.cntsmx;
    Node ans;
    ans.mx = max(a.mx, b.mx);
    ans.cntmx = mp[ans.mx];
    if (a.mx != ans.mx)
        ans.smx = max({a.mx, b.smx});
    else if (b.mx != ans.mx)
        ans.smx = max(a.smx, b.mx);
    else
        ans.smx = max(a.smx, b.smx);
    ans.cntsmx = mp[ans.smx];
    // printNode(ans);
    // cout << "--------------------------\n";
    return ans;
}

class SEGMENT_TREE {
   public:
    vector<int> v;
    vector<Node> seg;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    void build(int ti, int low, int high) {
        if (low == high) {
            seg[ti].mx = v[low];
            seg[ti].cntmx = 1;
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = pull(seg[2 * ti], seg[2 * ti + 1]);
    }
    Node find(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return Node();
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        Node l = find(2 * ti, tl, mid, ql, qr);
        Node r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return pull(l, r);
    }
    void update(int ti, int tl, int tr, int id, int val) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            seg[ti].mx = val;
            seg[ti].cntmx = 1;
            return;
        }
        int mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val);
        update(2 * ti + 1, mid + 1, tr, id, val);
        seg[ti] = pull(seg[2 * ti], seg[2 * ti + 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    SEGMENT_TREE seg(n);
    for (int i = 1; i <= n; i++)
        cin >> seg.v[i];
    seg.build(1, 1, n);
    for (int i = 1; i <= 15; i++) {
        cout << i << " --> ";
        printNode(seg.seg[i]);
    }
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        // if (type == 1)
        // seg.update(1, 1, n, l, r);
        // else
        // cout << seg.find(1, 1, n, l, r) << endl;
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
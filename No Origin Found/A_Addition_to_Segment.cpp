#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7, inf = 1e18, B = 22;

class Node {
   public:
    ll on[B], off[B];
    Node() {
        fill(on, on + B, 0);
        fill(off, off + B, 0);
    }
};

class SEGMENT_TREE {
   public:
    vector<ll> v;
    vector<Node> seg;
    vector<ll> lazy;
    SEGMENT_TREE(ll n) {
        v.resize(n + 5, 0);
        seg.resize(4 * n + 5, Node());
        lazy.resize(4 * n + 5, 0);
    }
    Node pull(Node a, Node b) {
        Node ans;
        for (int i = 0; i < B; i++) {
            ans.on[i] = a.on[i] + b.on[i];
            ans.off[i] = a.off[i] + b.off[i];
        }
        return ans;
    }
    void push(ll ti, ll tl, ll tr) {
        if (lazy[ti] == 0)
            return;

        for (int i = 0; i < B; i++) {
            if ((lazy[ti] >> i) & 1) {
                swap(seg[ti].on[i], seg[ti].off[i]);
            }
        }

        if (tl != tr) {
            lazy[2 * ti] ^= lazy[ti];
            lazy[2 * ti + 1] ^= lazy[ti];
        }
        lazy[ti] = 0;
    }
    //! llially: ti = 1, low = 1, high = n(number of elements in the array);
    void build(ll ti, ll low, ll high) {
        lazy[ti] = 0;
        if (low == high) {
            for (int i = 0; i < B; i++) {
                if ((v[low] >> i) & 1) {
                    seg[ti].on[i] = 1;
                    seg[ti].off[i] = 0;
                }
                else {
                    seg[ti].on[i] = 0;
                    seg[ti].off[i] = 1;
                }
            }
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = pull(seg[2 * ti], seg[2 * ti + 1]);
    }
    //! llially: ti = 1, low = 1, high = n(number of elements in the array), (ql
    //! & qr) = user input in 1 based indexing;
    Node query(ll ti, ll tl, ll tr, ll ql, ll qr) {
        push(ti, tl, tr);
        if (tl > qr || tr < ql) {
            return Node();
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        ll mid = (tl + tr) / 2;
        Node l = query(2 * ti, tl, mid, ql, qr);
        Node r = query(2 * ti + 1, mid + 1, tr, ql, qr);
        return pull(l, r);
    }
    //! llially: ti = 1, tl = 1, tr = n(number of elements in the array), id =
    //! user input in 1 based indexing, val = updated value;
    void update(ll ti, ll tl, ll tr, ll idL, ll idR, ll val) {
        push(ti, tl, tr);
        if (idR < tl or tr < idL)
            return;
        if (idL <= tl and tr <= idR) {
            lazy[ti] = val;
            push(ti, tl, tr);
            return;
        }
        ll mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, idL, idR, val);
        update(2 * ti + 1, mid + 1, tr, idL, idR, val);
        seg[ti] = pull(seg[2 * ti], seg[2 * ti + 1]);
    }
    // use 1 based indexing for input and queries and update;
};

void solve() {
    ll n, m;
    cin >> n;
    SEGMENT_TREE sg(n);
    for (int i = 1; i <= n; i++)
        cin >> sg.v[i];
    sg.build(1, 1, n);
    cin >> m;
    while (m--) {
        ll type;
        cin >> type;
        if (type == 2) {
            ll l, r, v;
            cin >> l >> r >> v;
            sg.update(1, 1, n, l, r, v);
        }
        else {
            ll l, r;
            cin >> l >> r;
            Node ans = sg.query(1, 1, n, l, r);
            ll sum = 0;
            for (int i = 0; i < B; i++)
                sum += (1LL << i) * ans.on[i];
            cout << sum << '\n';
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
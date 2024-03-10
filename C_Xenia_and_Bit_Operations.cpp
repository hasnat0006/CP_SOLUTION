//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|03|2024 14:38:27            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;

struct Node {
    int arr[27] = {0};
};

Node MARGE(Node &a, Node &b) {
    Node temp;
    for (int i = 0; i < 27; i++) {
        temp.arr[i] = a.arr[i] + b.arr[i];
    }
    return temp;
}

class SEGMENT_TREE {
   public:
    vector<char> v;
    vector<Node> seg;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array);
    void build(int ti, int low, int high) {
        if (low == high) {
            // seg[ti].s.insert(v[low]);
            seg[ti].arr[v[low] - 'a']++;
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = MARGE(seg[2 * ti], seg[2 * ti + 1]);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array), (ql & qr) = user input in 1 based indexing;
    Node find(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return Node();
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        Node l = find(2 * ti, tl, mid, ql, qr);
        Node r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return MARGE(l, r);
    }
    //! intially: ti = 1, tl = 1, tr = n(number of elements in the array), id = user input in 1 based indexing, val = updated value;
    void update(int ti, int tl, int tr, int id, char val) {
        if (id > tr or id < tl)
            return;
        if (id == tr and id == tl) {
            seg[ti].arr[v[id] - 'a']--;
            v[id] = val;
            seg[ti].arr[v[id] - 'a']++;
            return;
        }
        int mid = (tl + tr) / 2;
        update(2 * ti, tl, mid, id, val);
        update(2 * ti + 1, mid + 1, tr, id, val);
        seg[ti] = MARGE(seg[2 * ti], seg[2 * ti + 1]);
    }
};
// use 1 based indexing for input and queries and update;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    SEGMENT_TREE st(n);
    for (int i = 1; i <= n; i++) {
        st.v[i] = (s[i - 1]);
    }
    st.build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int type, l;
        cin >> type >> l;
        if (type == 1) {
            char c;
            cin >> c;
            st.update(1, 1, n, l, c);
        }
        else {
            int r;
            cin >> r;
            Node ans = st.find(1, 1, n, l, r);
            int cnt = 0;
            for (int i = 0; i < 27; i++) {
                if (ans.arr[i] > 0) {
                    cnt++;
                }
            }
            cout << cnt << endl;
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
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|03|2024 22:02:21            !//
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

string s;

bool isPalindrome(int l, int r) {
    // check if the string is palindrom or not between l to r length
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

set<int> marge(set<int> &a, set<int> &b, int l, int r) {
    set<int> c;
    for (auto &i : a) {
        c.insert(i);
    }
    for (auto &i : b) {
        c.insert(i);
    }
    if (!isPalindrome(l, r)) {
        c.insert(r - l + 1);
    }
    return c;
}

class SEGMENT_TREE {
   public:
    vector<int> v;
    vector<set<int>> seg;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array);
    void build(int ti, int low, int high) {
        if (low == high) {
            seg[ti] = {};
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = marge(seg[2 * ti], seg[2 * ti + 1], low, high);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array),
    //! (ql & qr) = user input in 1 based indexing;
    set<int> find(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return {};
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        set<int> l = find(2 * ti, tl, mid, ql, qr);
        set<int> r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return marge(l, r, tl, tr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    cin >> s;
    // SEGMENT_TREE st(n);
    // st.build(1, 0, n - 1);
    // for (int i = 1; i < 10; i++) {
    //     dbg(i, st.seg[i]);
    // }
    // while (q--) {
    //     int l, r;
    //     cin >> l >> r;
    //     if (l == r) {
    //         cout << 0 << endl;
    //         return;
    //     }
    //     set<int> ans = st.find(1, 0, n - 1, l - 1, r - 1);
    //     int sum = 0;
    //     for (auto &i : ans) {
    //         sum += i;
    //     }
    //     cout << sum << endl;
    // }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        set<int> ans;
        // check all subtring from l to r is palindrome or not
        for (int i = l; i <= r; i++) {
            for (int j = i; j <= r; j++) {
                if (!isPalindrome(i, j)) {
                    ans.insert(j - i + 1);
                }
            }
        }
        int sum = 0;
        for (auto &i : ans) {
            sum += i;
        }
        cout << sum << endl;
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
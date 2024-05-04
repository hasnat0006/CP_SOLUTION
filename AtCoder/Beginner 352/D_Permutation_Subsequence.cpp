//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|05|2024 18:44:47            !//
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

const int mod = 1e9 + 7;
const int inf = 1e18;

class SEGMENT_TREE {
   public:
    vector<int> v;
    vector<int> segMin, segMax;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        segMin.resize(4 * n + 5);
        segMax.resize(4 * n + 5);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array);
    void buildMin(int ti, int low, int high) {
        if (low == high) {
            segMin[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        buildMin(2 * ti, low, mid);
        buildMin(2 * ti + 1, mid + 1, high);
        segMin[ti] = min(segMin[2 * ti], segMin[2 * ti + 1]);
    }
    void buildMax(int ti, int low, int high) {
        if (low == high) {
            segMax[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        buildMax(2 * ti, low, mid);
        buildMax(2 * ti + 1, mid + 1, high);
        segMax[ti] = max(segMax[2 * ti], segMax[2 * ti + 1]);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array),
    //! (ql & qr) = user input in 1 based indexing;
    int findMin(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return inf;
        }
        if (tl >= ql and tr <= qr)
            return segMin[ti];
        int mid = (tl + tr) / 2;
        int l = findMin(2 * ti, tl, mid, ql, qr);
        int r = findMin(2 * ti + 1, mid + 1, tr, ql, qr);
        return min(l, r);
    }
    int findMax(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return -inf;
        }
        if (tl >= ql and tr <= qr)
            return segMax[ti];
        int mid = (tl + tr) / 2;
        int l = findMax(2 * ti, tl, mid, ql, qr);
        int r = findMax(2 * ti + 1, mid + 1, tr, ql, qr);
        return max(l, r);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    SEGMENT_TREE seg(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        seg.v[x] = i + 1;
    }
    seg.buildMin(1, 1, n);
    seg.buildMax(1, 1, n);
    int ans = n;
    for(int i = 1; i <= n - k + 1; i++){
        int mn = seg.findMin(1, 1, n, i, i + k - 1);
        int mx = seg.findMax(1, 1, n, i, i + k - 1);
        ans = min(ans, mx - mn);
    }
    cout << ans << endl;
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
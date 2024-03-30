//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

void build(int ti, int low, int high, vector<int> &v, vector<int> &seg_for_min, vector<int> &seg_for_max) {
    if (high == low) {
        seg_for_min[ti] = v[low];
        seg_for_max[ti] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ti + 1, low, mid, v, seg_for_min, seg_for_max);
    build(2 * ti + 2, mid + 1, high, v, seg_for_min, seg_for_max);
    seg_for_min[ti] = min(seg_for_min[2 * ti + 1], seg_for_min[ti * 2 + 2]);
    seg_for_max[ti] = max(seg_for_max[2 * ti + 1], seg_for_max[ti * 2 + 2]);
}
int find_for_min(int tl, int tr, int ql, int qr, int ti, vector<int> &v, vector<int> &seg_for_min) {
    if (tl > qr or tr < ql)
        return inf;
    if (tl >= ql and tr <= qr)
        return seg_for_min[ti];
    int mid = (tl + tr) / 2;
    int l = find_for_min(tl, mid, ql, qr, 2 * ti + 1, v, seg_for_min);
    int r = find_for_min(mid + 1, tr, ql, qr, 2 * ti + 2, v, seg_for_min);
    return min(l, r);
}

int find_for_max(int tl, int tr, int ql, int qr, int ti, vector<int> &v, vector<int> &seg_for_max) {
    if (tl > qr or tr < ql)
        return -1;
    if (tl >= ql and tr <= qr)
        return seg_for_max[ti];
    int mid = (tl + tr) / 2;
    int l = find_for_max(tl, mid, ql, qr, 2 * ti + 1, v, seg_for_max);
    int r = find_for_max(mid + 1, tr, ql, qr, 2 * ti + 2, v, seg_for_max);
    return max(l, r);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), seg_for_min(4 * n), seg_for_max(4 * n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    build(0, 0, n - 1, v, seg_for_min, seg_for_max);
    // debug(v);
    int samne = 0, piche = n - 1;
    bool f = false;
    while (1) {
        int mn = find_for_min(0, n - 1, samne, piche, 0, v, seg_for_min);
        int mx = find_for_max(0, n - 1, samne, piche, 0, v, seg_for_max);
        dbg(mn, mx);
        dbg(v[samne], v[piche]);
        if (min(v[samne], v[piche]) != mn and max(v[samne], v[piche]) != mx) {
            cout << samne + 1 << " " << piche + 1 << endl;
            return;
        }
        if (v[samne] == mx or v[samne] == mn)
            samne++;
        if (v[piche] == mx or v[piche] == mn)
            piche--;
        if (samne >= piche)
            break;
    }
    cout << -1 << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
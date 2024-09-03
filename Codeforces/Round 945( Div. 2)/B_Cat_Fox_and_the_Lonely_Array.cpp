//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|05|2024 21:02:36            !//
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
    vector<int> seg;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array);
    void build(int ti, int low, int high) {
        if (low == high) {
            seg[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = (seg[2 * ti] | seg[2 * ti + 1]);
    }
    //! intially: ti = 1, low = 1, high = n(number of elements in the array),
    //! (ql & qr) = user input in 1 based indexing;
    int find(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return 0;
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        int l = find(2 * ti, tl, mid, ql, qr);
        int r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return (l | r);
    }
    // use 1 based indexing for input and queries and update;
};

void solve() {
    int n;
    cin >> n;
    SEGMENT_TREE s(n);
    for (int i = 1; i <= n; i++) {
        cin >> s.v[i];
    }
    s.build(1, 1, n);

    auto isPossible = [&](int mid){
        set<int> st;
        for (int j = 1; j <= n - mid + 1; j++){
            int OR = s.find(1, 1, n, j, j + mid - 1);
            st.insert(OR);
            if(st.size() > 1)
                break;
        }
        return st.size() == 1;
    };
    int low = 1, high = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(isPossible(mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << low << endl;
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
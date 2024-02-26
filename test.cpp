//!-----------------------------------------------------!//
//!            Author: MIST_CG0_nai_CP0_nai             !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define endl "\n"

const int N = 4e6 + 5;
int a[2][N];
// order_set rmv;
int n, nn;


vector<int> seg(4 * N);
// index, low, high
void build(int ti, int low, int high) {
    if (high == low) {
        seg[ti] = 1;
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ti, low, mid);
    build(2 * ti + 1, mid + 1, high);
    seg[ti] = seg[2 * ti] + seg[ti * 2 + 1];
    cout << seg[ti] << " " << ti << " " << low << " " << high << endl;
}

int ans;
// index, tree left, tree right, query left, query right
void findValue(int ti, int tl, int tr, int idx) {
    if (tl == tr) {
        ans = tl;
        seg[ti] = 0;
        return;
    }
    int mid = (tl + tr) / 2;
    if (seg[2 * ti] >= idx)
        findValue(2 * ti, tl, mid, idx);
    else
        findValue(2 * ti + 1, mid + 1, tr, idx - seg[2 * ti]);
    seg[ti] = seg[2 * ti] + seg[2 * ti + 1];
}


void solve() {
    cin >> n;
    nn = n / 2;
    for (int i = 0; i < nn; i++)
        cin >> a[0][i];
    for (int i = 0; i < nn; i++)
        cin >> a[1][i];
    build(1, 1, n);
    for(int i = 0; i < 4 * nn;i++)
        cout << seg[i] << " ";
    cout << endl;
    vector<int> ansA, ansB;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            findValue(1, 1, n, a[1][i / 2]);
            ansB.push_back(ans);
        }
        else {
            findValue(1, 1, n, a[0][i / 2]);
            ansA.push_back(ans);
        }
    }
    for (auto i : ansA)
        cout << i << " ";
    cout << endl;
    for (auto i : ansB)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}

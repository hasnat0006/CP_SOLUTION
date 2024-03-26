//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|03|2024 02:34:39            !//
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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    auto XOR = [](int x, int y) {  return x ^ y; };
    partial_sum(vf(v), pre.begin(), XOR);
    dbg(pre);
    for (int i = 1; i <= n; i++) {
        int seg1 = pre[i];
        int seg2 = pre[n] ^ pre[i];
        dbg(i, seg1, seg2);
        if (seg1 == seg2) {
            cout << "YES" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        int seg1 = pre[i];
        int temp = XOR(pre[n], pre[i]);
        for (int j = i + 1; j < n; j++) {
            // i + 1 --- j
            int seg2 = pre[j] ^ seg1;
            // j + 1 --- n
            int seg3 = pre[n] ^ pre[j];
            if (seg1 == seg2 and seg2 == seg3) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
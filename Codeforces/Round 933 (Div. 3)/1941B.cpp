//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 20:54:44            !//
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
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    while (1) {
        int f = 0;
        for (int i = 1; i < n - 1; i++) {
            if (v[i - 1] > 0 and v[i] > 1 and v[i + 1] > 0) {
                int x = v[i - 1];
                int y = v[i + 1];
                int mn = min({x, y, v[i]});
                v[i - 1] -= mn;
                v[i] -= (mn * 2);
                v[i + 1] -= mn;
                if(v[i] < 0){
                    cout << "NO" << endl;
                    return;
                }
                f = 1;
            }
        }
        dbg(v);
        if (f == 0)
            break;
    }
    for (int i : v) {
        if (i != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|04|2024 21:29:40            !//
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

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    if (n == m) {
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            else {
                if (a[i] > b[i]) {
                    dbg(i);
                    for (int j = i + 1; j < n; j++) {
                        char x = a[j], y = b[j];
                        b[j] = max(x, y);
                        a[j] = min(x, y);
                    }
                    break;
                }
                else {
                    for (int j = i + 1; j < n; j++) {
                        char x = a[j], y = b[j];
                        b[j] = min(x, y);
                        a[j] = max(x, y);
                    }
                    break;
                }
            }
            dbg(a, b);
        }
    }
    else if (n > m) {
        reverse(vf(a));
        reverse(vf(b));
        for (int i = 0; i < m; i++) {
            if(a[i] > b[i])
                swap(a[i], b[i]);
        }
        reverse(vf(a));
        reverse(vf(b));
    }
    else {
        reverse(vf(a));
        reverse(vf(b));
        for (int i = 0; i < n; i++) {
            if(a[i] < b[i])
                swap(a[i], b[i]);
        }
        reverse(vf(a));
        reverse(vf(b));
    }
    cout << a << endl << b << endl;
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
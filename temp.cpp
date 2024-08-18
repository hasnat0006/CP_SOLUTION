//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|08|2024 23:39:51            !//
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m, 0)), a(n, vector<int>(m, 0)),
        c(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            b[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = (b[i][j] - a[i][j] + 3) % 3;
        }
    }
    dbg(c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = c[i][j];
            if (!x)
                continue;
            int flag = 0;
            for (int k = 0; k < n; k++) {
                if (k == i)
                    continue;
                for (int l = 0; l < m; l++) {
                    if (l == j) {
                        continue;
                    }
                    if (c[k][l] == x && (c[i][l] == c[k][j])) {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag) {
                dbg(i, j);
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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
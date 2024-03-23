//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|03|2024 01:45:41            !//
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
    string s;
    cin >> n >> s;
    vector<int> left(n), right(n + 5);
    int cntLeft = count(vf(s), '0');
    int cntRight = count(vf(s), '1');
    cntLeft = ceil(cntLeft / 2.0);
    cntRight = ceil(cntRight / 2.0);
    left[0] = s[0] == '0';
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1] + (s[i] == '0');
    }
    right[n - 1] = s[n - 1] == '1';
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] + (s[i] == '1');
    }
    vector<pair<float, int>> p;
    for (int i = 0; i <= n; i++) {
        int l = 0, r = 0;
        if (i != 0)
            l = left[i - 1];
        int x = (i + 1) / 2;
        if (x <= l) {
            if (i != n)
                r = right[i];
            x = (n - i + 1) / 2;
            if (x <= r) {
                p.push_back({abs(n / 2.0 - i), i});
            }
        }
    }
    sort(vf(p));
    cout << p[0].second << endl;
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
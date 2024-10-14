//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|03|2024 03:23:55            !//
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    if (n == k) {
        cout << fixed << setprecision(10) << accumulate(vf(v), 0ll) * 1.0 << endl;
        return;
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < n / 2; i++) {
        cnt[i] = cnt[n - i - 1] = min({n - k + 1, i + 1, k});
    }
    if (n % 2) {
        cnt[n / 2] = cnt[n / 2 - 1] >= k - 1 ? k : cnt[n / 2 - 1];
    }
    dbg(cnt);
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (v[i] * cnt[i]);
    }
    cout << fixed << setprecision(10) << sum / (n - k + 1) << endl;
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
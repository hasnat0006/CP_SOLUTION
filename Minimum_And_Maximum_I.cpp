//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|02|2024 21:44:52            !//
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

    auto conSum = [](int n) {
        return n * (n + 1) / 2;
    };

    n % 2 ? cout << 2 * conSum(n / 2) + ((n+1)/2) << endl : cout << 2 * conSum(n / 2) << endl;
    // vector<int> a;
    // int small = 1, big = n;
    // for (int i = 0; i < n; i++) {
    //     if (i % 2)
    //         a.push_back(big--);
    //     else
    //         a.push_back(small++);
    // }
    // a.push_back(a[0]);
    // dbg(a);
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    //     ans += min(a[i], a[i - 1]);
    // cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
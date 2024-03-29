//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|03|2024 23:57:58            !//
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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if(n == 1){
        cout << b * v.front() << endl;
        return;
    }
    vector<pair<int, int>> vp(n);
    int ans = b * v[0];
    vp[0].first = b * v[0], vp[0].second = a * v[0];
    for (int i = 1; i < n; i++) {
        ans += (b * v[i]);
        vp[i].first = b * (v[i] - v[i - 1]);
        vp[i].second = a * (v[i]);
    }
    vector<int> till(n);
    till[0] = vp[0].first + vp[0].second;
    for (int i = 1; i < n; i++) {
        till[i] = till[i - 1] + vp[i].first + vp[i].second - vp[i - 1].second;
    }
    vector<int> suff(n);
    partial_sum(vr(v), suff.rbegin());
    ans = min(ans, till.back() - vp.back().second + vp[n - 2].second);
    for (int i = 0; i < n - 1; i++) {
        int tempAns = till[i] + (b * (suff[i + 1] - (v[i] * (n - 1 - i))));
        ans = min(ans, tempAns);
    }
    cout << ans << endl;
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
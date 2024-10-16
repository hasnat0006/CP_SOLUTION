//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|10|2024 20:45:05            !//
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(vf(v));
    if(k == 1){
        cout << 2 * v.back() + v.front() + v[n - 2] << endl;
        return;
    }
    int ans = v.back();
    v.pop_back();
    reverse(vf(v));
    int mn = ans;
    // cerr << ans << endl;
    k = n - k - 1;
    while (k--) {
        mn = min(v.back(), mn);
        v.pop_back();
    }
    dbg(v);
    ans += mn;
    // cerr << ans << endl;
    ans += v.back() + v.front();
    // cerr << ans << endl;
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
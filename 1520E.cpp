//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|03|2024 02:21:02            !//
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
    string s;
    cin >> s;
    vector<int> id;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') 
            id.push_back(i);
    }
    if (id.size() == 0 or id.size() == n or id.size() == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> pre(id.size(), 0), suf(id.size(), 0);
    pre[0] = 0;
    for (int i = 1; i < id.size(); i++) 
        pre[i] = pre[i - 1] + (id[i] - id[i - 1] - 1) * i;
    suf[id.size() - 1] = 0;
    for (int i = id.size() - 2; i >= 0; i--) 
        suf[i] = suf[i + 1] + (id[i + 1] - id[i] - 1) * (id.size() - i - 1);
    int ans = inf;
    for (int i = 0; i < id.size(); i++)
        ans = min(ans, pre[i] + suf[i]);
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
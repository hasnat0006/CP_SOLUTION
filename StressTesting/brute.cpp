//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|04|2024 22:57:59            !//
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n), c(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, int> mp, store, allvalid;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        mp[c[i]]++;
    }
    int ans = 0, storeCnt = 0;
    for (int i = 0; i <= n - m; i++) {
        map<int, int> temp = mp;
        int cnt = 0;
        for(int j = i; j < i + m; j++){
            if(temp[v[j]] > 0)
                temp[v[j]]--, cnt++;
            if(cnt >= k){
                ans++;
                break;
            }
        }
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
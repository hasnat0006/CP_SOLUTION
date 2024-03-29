//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|03|2024 16:07:43            !//
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }
    sort(vf(a));
    vector<int> diff;
    for (int i = 1; i < n; i++)
        diff.push_back(a[i] - a[i - 1]);
    sort(vf(diff));
    // dbg(diff);
    if (k == 1) {
        cout << min(a.front(), diff.front()) << endl;
        return;
    }
    map<int, int> mp;
    for (int i = 0; i < a.size(); i++) {
        mp[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            diff.push_back(abs(a[i] - a[j]));
        }
    }
    sort(vf(diff));
    a.push_back(inf);
    int ans = inf;
    for (int i = 0; i < diff.size(); i++) {
        if(mp[diff[i]]) {
            cout << 0 << endl;
            return;
        }
        int id = lower_bound(vf(a), diff[i]) - a.begin();
        if (id - 1 >= 0)
            ans = min(ans, abs(diff[i] - a[id - 1]));
        ans = min(ans, abs(diff[i] - a[id]));
    }
    cout << min({ans, diff.front(), a.front()}) << endl;
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
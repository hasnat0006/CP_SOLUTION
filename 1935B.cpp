//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|03|2024 21:02:00            !//
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
    vector<int> v(n), freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    int firstNotOccur = -1;
    for (int i = 0; i <= n; i++) {
        if (freq[i] == 0) {
            firstNotOccur = i;
            break;
        }
    }
    dbg(firstNotOccur);
    set<int> s;
    int st = 1;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (v[i] < firstNotOccur)
            s.insert(v[i]);
        if (s.size() == firstNotOccur) {
            if (ans.size() == 1) {
                ans.push_back({st, n});
                break;
            }
            else
                ans.push_back({st, i + 1});
            st = i + 2;
            s.clear();
        }
    }

    if (ans.size() < 2) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }
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
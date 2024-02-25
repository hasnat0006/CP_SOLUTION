//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|02|2024 20:53:56            !//
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
    vector<int> health(n), location(n);
    for (int i = 0; i < n; i++)
        cin >> health[i];
    for (int i = 0; i < n; i++)
        cin >> location[i];
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[abs(location[i])] += health[i];
    vector<pair<int, int>> v;
    v.push_back({0, 0});
    for (auto i : m)
        v.push_back({i.first, i.second});
    dbg(v);
    int cur = 0;
    for(int i = 1; i < v.size(); i++) {
        cur = cur + (v[i].first - v[i - 1].first) * k;
        if(cur < v[i].second) {
            cout << "NO" << endl;
            return;
        }
        cur = cur - v[i].second;
        dbg(cur);
    }
    cout << "YES" << endl;
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
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|09|2024 21:24:59            !//
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
    int n;
    cin >> n;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    map<int, vector<int>> mp;
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        vector<int> cycle;
        int j = v[i];
        mp[j].push_back(j);
        visited[j] = 1;
        dbg(i, j, v[j], v[i]);
        while (v[j] != v[i]) {
            dbg(j, v[j]);
            mp[v[i]].push_back(v[j]);
            j = v[j];
            visited[j] = 1;
        }
    }
    dbg(mp);
    vector<int> ans(n + 1);
    for (auto &x : mp) {
        int cnt = 0;
        for (auto& it : x.second) {
            if (s[it - 1] == '0') {
                cnt++;
            }
        }
        for(auto &it : x.second){
            ans[it] = cnt;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 21:52:17            !//
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
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<pair<int, int>> ans;
    for (auto x : mp) {
        ans.push_back({x.first, x.second});
    }
    map<int, int> parbo;
    for(auto x: ans){
        parbo[x.first] = x.first;
    }
    sort(vr(ans));
    dbg(ans);
    int m = ans.size();
    for (int i = 0; i < m; i++) {
        if(mp[ans[i].first - 1] > 0){
            parbo[ans[i].first - 1] = parbo[ans[i].first];
        }
    }
    dbg(parbo);
    map<int, int> temp;
    for (int i = 0; i < m; i++) {
        temp[ans[i].first] = temp[ans[i].first + 1] + ans[i].second;
    }
    for(auto x: temp){
        if(x.second == 0){
            temp.erase(x.first);
        }
    }
    dbg(temp);
    int mx = 0;
    for (int i = m - 1; i >= 0; i--) {
        int jaiteParbo = parbo[ans[i].first];
        if(ans[i].first + x - 1 < jaiteParbo)
            jaiteParbo = ans[i].first + x - 1;
        int high = temp.count(ans[i].first) ? temp[ans[i].first] : 0;
        int baad = temp.count(jaiteParbo + 1) ? temp[jaiteParbo + 1] : 0;
        dbg(ans[i].first, jaiteParbo, high, baad);
        mx = max(mx, high - baad);
    }
    dbg(temp);
    cout << mx << endl;
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
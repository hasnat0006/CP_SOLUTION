//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|06|2024 20:58:01            !//
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
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int cnt = 0;
    map<char, set<int>> mp;
    for (int i = 0; i < m; i++) {
        mp[b[i]].insert(i);
    }
    for(auto it : mp){
        dbg(it.first, it.second);
        if(a.find(it.first) == string::npos){
            continue;
        }
        for(auto i : it.second){
            int temp = 1, id = i;
            dbg(id);
            for(int c = 01; c < n; c++){
                if(mp[a[c]].find(id + 1) != mp[a[c]].end()){
                    temp++;
                    id++;
                }
                dbg(temp, id, a[c]);
            }
            dbg(temp, id, i);
            cnt = max(cnt, temp);
        }
        dbg(cnt);
    }
    // for (auto i : mp[a.front()]) {
    //     int temp = 1, id = i;
    //     dbg(id);
    //     for (int c = 1; c < n; c++) {
    //         if (mp[a[c]].find(id + 1) != mp[a[c]].end()) {
    //             temp++;
    //             id++;
    //         }
    //         dbg(temp, id, a[c]);
    //     }
    //     dbg(temp, id, i);
    //     cnt = max(cnt, temp);
    // }
    dbg(cnt);
    cout << n + m - cnt << endl;
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
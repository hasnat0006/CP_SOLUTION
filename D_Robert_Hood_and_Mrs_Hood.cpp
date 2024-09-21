//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 21|09|2024 22:46:45            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> start(k);
    vector<pair<int, int>> task(k);
    map<int, int> mp;
    for(int i = 0; i < k; i++){
        cin >> task[i].first >> task[i].second;
        start[i] = task[i].first;
        mp[task[i].first]++;
        mp[task[i].second + 1]--;
    }
    vector<int> totalTask(n + 1);
    for(int i = 1; i <= n; i++){
        totalTask[i] = totalTask[i - 1] + mp[i];
    }
    dbg(totalTask);
    sort(vf(start));
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n - d + 1; i++){
        int cur = totalTask[i];
        int stay = i + d - 1;
        int idx = upper_bound(vf(start), i) - start.begin();
        int achebesi = k - idx;
        int idy = upper_bound(vf(start), stay) - start.begin();
        int baaddibo = k - idy;
        dbg(i, cur, achebesi, baaddibo);
        int extra = achebesi - baaddibo;
        ans.push_back({i, (cur + extra)});
    }
    dbg(ans);
    int maxTaskDay = -inf, minTaskDay = inf;
    int maxTask = -inf, minTask = inf;
    for(auto x : ans){
        if(x.second > maxTask){
            maxTask = x.second;
            maxTaskDay = x.first;
        }
        if(x.second < minTask){
            minTask = x.second;
            minTaskDay = x.first;
        }
        dbg(x.first, x.second, maxTaskDay, minTaskDay);
    }
    cout << maxTaskDay << " " << minTaskDay << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}
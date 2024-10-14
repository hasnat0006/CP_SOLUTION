//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|04|2024 23:39:38            !//
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

#define mod 1000000007;
#define inf 1000000000000000000;

vector<int> v;
map<int, int> mp;
vector<int> dp(100005, -1);

int findAns(int id){
    if(id <= 1)
        return mp[id];
    if(dp[id] != -1)
        return dp[id];
    int notTake = findAns(id - 1);
    int take = (mp[id] * id) + findAns(id - 2);
    return dp[id] = max(take, notTake);
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i], mp[v[i]]++;
    int mx = *max_element(vf(v));
    cout << findAns(mx) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|03|2024 03:04:18            !//
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

vector<int> fact;
map<int, int> mp;

void findSubset(int n, vector<int> v = {}) {
    if (n == -1) {
        int sum = 0;
        for (auto i : v)
            sum += i;
        if (sum > (int)1e12)
            return;
        if (mp[sum] != 0)
            mp[sum] = min(mp[sum], (int)v.size());
        else
            mp[sum] = v.size();
        return;
    }
    findSubset(n - 1, v);
    v.push_back(fact[n]);
    findSubset(n - 1, v);
    v.pop_back();
}

void solve() {
    int n;
    cin >> n;
    int ans = inf;
    for (auto i : mp) {
        if (i.first <= n) {
            int x = n - i.first;
            ans = min(ans, (i.second + __builtin_popcountll(n - i.first)));
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    fact.push_back(1);
    int i = 1;
    while (fact.back() < (int)1e12)
        fact.push_back(fact.back() * i++);
    if (fact.back() > (int)1e12)
        fact.pop_back();
    findSubset(fact.size() - 1);
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|05|2024 21:49:59            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
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
const int inf = mod;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<deque<int>, int> mp;
    deque<int> dq;
    dq.push_back(v[0]);
    dq.push_back(v[1]);
    for (int i = 2; i < n; i++) {
        dq.push_back(v[i]);
        mp[dq]++;
        dq.pop_front();
    }
    dbg(mp);
    map<vector<int>, int> cnt;
    for (auto i : mp) {
        int a = i.first[0];
        int b = i.first[1];
        int c = i.first[2];
        cnt[{inf, b, c}] += i.second;
        cnt[{a, inf, c}] += i.second;
        cnt[{a, b, inf}] += i.second;
    }
    dbg(cnt);
    int ans = 0;
    for (auto i : mp) {
        int sum = cnt[{inf, i.first[1], i.first[2]}] - mp[i.first];
        sum += cnt[{i.first[0], inf, i.first[2]}] - mp[i.first];
        sum += cnt[{i.first[0], i.first[1], inf}] - mp[i.first];
        sum *= i.second;
        ans += sum;
        dbg(sum, ans);
        dbg(i.first[0], i.first[1], i.first[2], sum);
    }
    cout << ans / 2 << endl;
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
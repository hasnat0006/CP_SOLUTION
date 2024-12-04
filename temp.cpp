//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#endif
using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = mod;

void solve() {
    ll n;
    string s, p;
    vector<ll> a, b;
    cin >> n >> s >> p;
    map<char, ll> id;
    s = "#" + s;
    p = "#" + p;
    a.clear(), b.clear();
    a.resize(s.size()), b.resize(s.size());
    for (int i = 0; i < p.size(); i++) {
        id[p[i]] = i;
    }
    string temp = "#";
    for (int i = 1; i < s.size(); i++) {
        ll index = 27 - id[s[i]];
        temp.push_back(p[index]);
    }
    for (int i = 1; i < s.size(); i++) {
        a[i] = s[i] - 'a' + 1;
        b[i] = temp[i] - 'a' + 1;
    }
    ll dp[s.size()][30];
    memset(dp, -1, sizeof(dp));
    function<ll(ll, ll)> findMinCost = [&] (int i, int last) {
        if (i == 0)
            return 0;
        if (dp[i][last] != -1)
            return dp[i][last];
        ll ans1 = inf, ans2 = inf;
        if (a[i] <= last)
            ans1 = findMinCost(i - 1, a[i]);
        if (b[i] <= last)
            ans2 = 1 + findMinCost(i - 1, b[i]);
        return dp[i][last] = min(ans1, ans2);
    };

    ll ans = findMinCost(s.size() - 1, 28);
    cout << (ans == mod ? -1 : ans) << '\n';

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
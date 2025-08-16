#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<ll, vector<ll>> mp;
    for(int i = 0; i < n; i++) {
        mp[s[i]].push_back(i);
    }
    dbg(mp);
    vector<ll> v(n + 5);
    for(auto [c, vv] : mp) {
        v[vv.front()]++;
        v[vv.back() + 1]--;
    }
    dbg(v);
    vector<ll> pre(n + 5);
    partial_sum(vf(v), pre.begin());
    dbg(pre);
    ll mx = *max_element(vf(pre));
    cout << (mx > k ? "YES" : "NO") << '\n';
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
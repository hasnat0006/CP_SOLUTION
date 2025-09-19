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
    ll n;
    cin >> n;
    map<ll, ll> mp;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll sum = 0;
    dbg(mp);
    vector<ll> ans(n), c(n + 1, 0);
    map<ll, vector<ll>> emni;
    ll j = 1;
    for (auto [val, cnt] : mp) {
        if (cnt % val > 0) {
            cout << -1 << '\n';
            return;
        }
        ll div = cnt / val;
        while (div--) {
            emni[val].push_back(j);
            c[j++] = val;
        }
    }
    dbg(c);
    for (int i = 0; i < n; i++) {
        ans[i] = emni[v[i]].back();
        c[emni[v[i]].back()]--;
        if (c[emni[v[i]].back()] == 0)
            emni[v[i]].pop_back();
    }
    for (auto i : ans)
        cout << i << " ";
    cout << '\n';
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
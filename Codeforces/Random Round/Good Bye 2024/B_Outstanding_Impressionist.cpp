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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = mod;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    map<int, int> freqA, freqB;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first == v[i].second) {
            freqA[v[i].first]++;
            freqB[v[i].first] = 1;
        }
    }
    vector<ll> pre(2 * n + 5, 0);
    for (int i = 1; i <= 2 * n; i++) {
        pre[i] = pre[i - 1] + freqB[i];
    }
    dbg(pre);
    for (auto [l, r] : v) {
        if (l == r)
            cout << (freqA[l] == 1 ? "1" : "0");
        else {
            ll rangePrefixSum = pre[r] - pre[l - 1];
            cout << (rangePrefixSum < (r - l + 1) ? "1" : "0");
        }
    }
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
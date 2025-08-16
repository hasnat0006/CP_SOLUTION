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
    vector<ll> v(n), pre(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= n;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            cout << 1 << '\n' << i + 1 << '\n';
            return;
        }
    }
    pre[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre[i] = (pre[i - 1] + v[i]) % n;
    }
    map<ll, ll> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        if (mp.count(pre[i])) {
            ll len = i - mp[pre[i]];
            cout << len << '\n';
            ll c = mp[pre[i]] + 1;
            while (c <= i) 
                cout << ++c << " ";
            cout << '\n';
            return;
        }
        mp[pre[i]] = i;
    }
    cout << -1 << '\n';
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
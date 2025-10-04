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
    ll l, r;
    cin >> l >> r;
    cout << (r * (r + 1)) << '\n';

    map<ll, ll> mp;
    vector<ll> v(r + 5);
    for (int i = r; i >= 0; i--) {
        if (v[i])
            continue;
        bitset<25> b(i);
        bitset<25> notun;
        ll f = 0;
        for (int bit = 24; bit >= 0; bit--) {
            if (b[bit] == 1)
                f = 1;
            if (f and b[bit] == 0)
                notun[bit] = 1;
        }
        dbg(b);
        dbg(notun);

        dbg(i, notun.to_ullong());
        mp[i] = notun.to_ullong();
        mp[notun.to_ullong()] = i;
        v[i] = v[notun.to_ullong()] = 1;
    }
    for (int i = 0; i <= r; i++)
        cout << mp[i] << " ";
    cout << '\n';

    ll sum = 0;
    for(int i = 0; i <= r; i++) {
        sum += (i | mp[i]);
    }
    dbg(sum);
    dbg("_________________");
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
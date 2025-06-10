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
    vector<ll> a(n);
    map<ll, ll> mp, done;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0, freq = inf;
    for(int i = 0; i < n; i++) {
        if(done.count(a[i]))
            continue;
        done[a[i]] = 1;
        freq = min(freq, mp[a[i]]);
        ans = max(ans, freq);
    }
    cout << ans << "\n";
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
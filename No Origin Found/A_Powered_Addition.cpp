#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll ans = 0, till = 0;
    for (int i = 1; i < n; i++) {
        if(v[i] >= v[i - 1])
            continue;
        if (v[i] + till >= v[i - 1]) {
            v[i] = v[i - 1];
        }
        else if (v[i] < v[i - 1]) {
            ll need = v[i - 1] - v[i];
            ll power = log2(need);
            dbg(power);
            till = (1LL << power);
            v[i] = v[i - 1];
            power++;
            dbg(i, power, ans, need);
            ans = max(ans, power);
        }
        dbg(v);
    }
    cout << ans << endl;
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
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
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(vf(v));

    vector<ll> pre(n + 2), suf(n + 2);
    ll sum = 0, l = 1, r;
    for (int i = 1; i <= n; i++) {
        sum += v[i].second;
        while (v[i].first - v[l].first > d) {
            sum -= v[l].second;
            l++;
        }
        pre[i] = max(pre[i - 1], sum);
    }

    sum = 0, r = n;
    for (int i = n; i > 0; i--) {
        sum += v[i].second;
        while (v[r].first - v[i].first > d) {
            sum -= v[r].second;
            r--;
        }
        suf[i] = max(suf[i + 1], sum);
    }
    dbg(pre);
    dbg(suf);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    cout << ans << '\n';
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
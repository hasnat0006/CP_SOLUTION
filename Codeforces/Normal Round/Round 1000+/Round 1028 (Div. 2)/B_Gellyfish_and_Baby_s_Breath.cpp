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

const ll mod = 998244353;
const ll inf = 1e18;

const ll N = 1e5 + 5;
vector<ll> pre(N, 0);

void precompute() {
    pre[0] = 1;
    for (ll i = 1; i < N; i++) {
        pre[i] = (pre[i - 1] * 2) % mod;
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n), q(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        // p[i] = pre[p[i]];
    }
    for (ll i = 0; i < n; i++) {
        cin >> q[i];
        // q[i] = pre[q[i]];
    }
    dbg(p);
    dbg(q);
    ll mxp = -1, mxq = -1, mxpId = -1, mxqId = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] > mxp) {
            mxp = p[i];
            mxpId = i;
        }
        if (q[i] > mxq) {
            mxq = q[i];
            mxqId = i;
        }

        ll x, y;
        if (mxp > mxq)
            x = mxp, y = q[i - mxpId];
        else if (mxq > mxp)
            x = mxq, y = p[i - mxqId];
        else {
            ll y1 = q[i - mxpId];
            ll x2 = p[i - mxqId];
            if (y1 >= x2) {
                x = mxp;
                y = y1;
            }
            else {
                x = mxq;
                y = x2;
            }
        }
        ll ans = (pre[x] + pre[y]) % mod;
        cout << ans % mod << " ";
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    precompute();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
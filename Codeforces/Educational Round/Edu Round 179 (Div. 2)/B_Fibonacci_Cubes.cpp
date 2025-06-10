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

vector<ll> fib;
void prec() {
    fib.push_back(1);
    fib.push_back(1);
    for (int i = 2; i <= 12; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll w, l, h;
        cin >> w >> l >> h;
        if (w < fib[n] or l < fib[n] or h < fib[n])
            cout << 0;
        else {
            ll mx = max({w, l, h});
            ll rem = mx - fib[n];
            if (rem >= fib[n - 1])
                cout << 1;
            else
                cout << 0;
        }
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    prec();
    // dbg(fib);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
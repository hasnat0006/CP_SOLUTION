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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> exclude(m);
    set<ll> know;
    for (int i = 0; i < m; i++)
        cin >> exclude[i];
    for (int i = 0; i < k; i++) {
        ll x;
        cin >> x;
        know.insert(x);
    }
    dbg(know);

    if (k < n - 1) {
        for (int i = 0; i < m; i++)
            cout << 0;
        cout << '\n';
        return;
    }
    for (int i = 0; i < m; i++) {
        ll pari = k, drkr = n - 1;

        if (know.find(exclude[i]) != know.end()) {
            // para quesiton ashe nai
            pari--;
        }
        dbg(pari, drkr);
        cout << (pari < n - 1 ? 0 : 1);
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
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<bitset<100>> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = bitset<100>(a[i]);
    }
    // dbg(b);
    for (int bit = 0; bit < 100; bit++) {
        ll f = 0;
        for (int i = 0; i < n; i++) {
            if (b[i][bit] == 0) {
                ll need = (1LL << bit);
                dbg(i, bit, need, k);
                if (need > k) {
                    f = 1;
                    break;
                }
                k -= need;
                b[i][bit] = 1;
            }
        }
        if(f)
            break;
    }
    dbg(b);
    ll cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += b[i].count();
    cout << cnt << endl;
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
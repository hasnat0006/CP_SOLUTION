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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    iota(vf(v), 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (n - i + 1);
    }
    dbg(sum);

    auto rangeSum = [&] () {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ll mn = inf;
                for (int k = i; k <= j; k++) {
                    mn = min(mn, v[k]);
                }
                sum += mn;
            }
        }
        return sum;
    };

    dbg(rangeSum());
    ll cnt = 0;
    do {
        if (sum == rangeSum()) {
            dbg(v);
            cnt++;
        }
    } while (next_permutation(vf(v)));
    dbg(cnt);

    // ll max_possible = binaryExp()
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
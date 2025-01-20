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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (v[i] >= v[i + 1]) {
                if (v[i + 1] * 2 > v[i]) {
                    ans = 1;
                    break;
                }
            }
        }
        else if (i == n - 1) {
            if (v[i] >= v[i - 1]) {
                if (2 * v[i - 1] > v[i]) {
                    ans = 1;
                    break;
                }
            }
        }
        else {
            if (v[i] >= v[i - 1] and 2 * v[i - 1] > v[i]) {
                ans = 1;
                break;
            }
            if (v[i] >= v[i + 1] and 2 * v[i + 1] > v[i]) {
                ans = 1;
                break;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
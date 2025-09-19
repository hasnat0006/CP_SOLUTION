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

void solve(ll n) {
    vector<ll> L = {1}, R = {1};
    ll val = 5;
    ll p = 1;
    while (val <= inf * 2) {
        L.push_back(L.back() + val);
        val *= 4;
        p *= 4;
        R.push_back(L.back() + p - 1);
    }
    for (int i = 0; i < L.size(); i++) {
        if (n >= L[i] and n <= R[i]) {
            cout << "Aoki" << '\n';
            return;
        }
    }
    cout << "Takahashi" << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        ll x = i;
        cin >> x;
        solve(x);
    }
    return 0;
}
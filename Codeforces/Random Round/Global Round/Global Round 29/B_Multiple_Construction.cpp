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
    vector<ll> ans(2 * n + 1);
    ll even = (n % 2 ? n - 1 : n), odd = (n % 2 ? n : n - 1), i = 1;
    while (i <= n) {
        if (i % 2) {
            ans[i] = odd;
            odd -= 2;
        }
        else {
            ans[i] = even;
            even -= 2;
        }
        i++;
    }
    for (int id = 1; id <= n; id++) {
        if (ans[id] == 1)
            continue;
        ll nextI = id + ans[id];
        while (ans[nextI] != 0) {
            nextI += ans[id];
        }
        if (nextI > (2 * n)) {
            dbg(id);
        }
        ans[nextI] = ans[id];
    }
    for (int id = 1; id <= 2 * n; id++) {
        cout << (ans[id] == 0 ? 1 : ans[id]) << " ";
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
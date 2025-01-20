#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.cpp"
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
    int n;
    cin >> n;
    vector<ll> a(n), b(n), pos, neg;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i])
            pos.push_back(a[i] - b[i]);
        else
            neg.push_back(b[i] - a[i]);
    }
    if (neg.empty()) {
        cout << "YES" << '\n';
        return;
    }
    if (neg.size() > 1) {
        cout << "NO" << '\n';
        return;
    }
    sort(vf(pos));
    cout << (neg.front() <= pos.front() ? "YES" : "NO") << '\n';
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
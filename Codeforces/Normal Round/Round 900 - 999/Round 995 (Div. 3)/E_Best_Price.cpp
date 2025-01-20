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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    set<ll> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        st.insert(b[i]);
    }
    sort(vf(a));
    sort(vf(b));
    ll ans = 0;
    for (auto i : st) {
        ll idA = lower_bound(vf(a), i) - a.begin();
        ll idB = lower_bound(vf(b), i) - b.begin();
        if ((n - idB) - (n - idA) <= k)
            ans = max(ans, i * (n - idB));
    }
    cout << ans << '\n';
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
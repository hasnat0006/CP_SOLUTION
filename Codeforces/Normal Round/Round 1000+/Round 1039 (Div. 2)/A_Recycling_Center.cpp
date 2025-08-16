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
    set<pair<ll, ll>> st;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        st.insert({x, i});
    }
    ll c = 0;
    while (k > 1 and st.size()) {
        auto it = st.upper_bound({k, -1});
        if (it == st.begin()) {
            break;
        }
        it--;
        st.erase(it);
        c++;
        k /= 2;
    }
    cout << n - c << '\n';
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
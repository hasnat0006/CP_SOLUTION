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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if (a.back() != b.back()) {
        cout << "NO" << '\n';
        return;
    }
    dbg("-------");
    set<ll> st;
    st.insert(a.back());
    st.insert(0);
    for (int i = n - 2; i >= 0; i--) {
        ll need = b[i] ^ a[i];
        dbg(need, st);
        if (st.find(need) == st.end()) {
            cout << "NO" << '\n';
            return;
        }
        st.clear();
        st.insert(0);
        st.insert(a[i]), st.insert(b[i]);
        dbg(i);
    }
    cout << "YES" << '\n';
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
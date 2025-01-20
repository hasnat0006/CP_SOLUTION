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
    ll n;
    cin >> n;
    vector<ll> v(n);
    set<ll> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st.insert(i + 1);
    }
    dbg(v);
    dbg(st);
    for (int i = 0; i < n; i++) {
        if (st.find(v[i]) != st.end()) {
            cout << v[i] << " ";
            st.erase(st.find(v[i]));
        }
        else {
            cout << *st.begin() << " ";
            st.erase(st.begin());
        }
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
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
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (v[i] > v[k - 1])
            st.insert(v[i]);
    }
    dbg(st);
    ll myPos = v[k - 1] + 1, water_level = 1;
    for (auto i : st) {
        ll timeHere = i - myPos;
        water_level += timeHere;
        dbg(water_level, timeHere, i, myPos);
        if (water_level >= myPos) {
            cout << "NO\n";
            return;
        }
        myPos = i + 1;
        water_level++;
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
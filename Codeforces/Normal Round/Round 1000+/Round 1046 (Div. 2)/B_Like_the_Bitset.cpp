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
    ll mx = 0, temp = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            temp++;
        else
            temp = 0;
        mx = max(mx, temp);
    }
    dbg(mx);
    if (mx >= k) {
        cout << "NO" << '\n';
        return;
    }
    vector<ll> ans(n);
    ll c = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            ans[i] = c++;
    }
    cout << "YES" << '\n';
    for (auto i : ans) {
        cout << (i == 0 ? c++ : i) << " ";
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
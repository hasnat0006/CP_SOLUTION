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
    string s;
    cin >> n >> s;
    ll ans = 0;
    s = "?" + s + "???";
    for (int i = 1; i < n; i++) {
        if (i % 2 and s[i] == '0')
            continue;
        if (i % 2 == 0 and s[i] == '1')
            continue;
        s[i] = (s[i] == '0' ? '1' : '0');
        s[i + 1] = (s[i + 1] == '0' ? '1' : '0');
        s[i + 2] = (s[i + 2] == '0' ? '1' : '0');
        ans++;
        dbg(i, s);
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
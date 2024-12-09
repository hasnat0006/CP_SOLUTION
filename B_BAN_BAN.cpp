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
    string ban = "BAN", s = "";
    while (n--) {
        s += ban;
    }
    n = s.size();
    vector<pair<long long, long long>> v;
    ll i = 0, j = n - 2, f = 0;
    while (i <= j) {
        if (s[i] == 'B' and s[j] == 'A') {
            swap(s[i], s[j]);
            v.push_back({i, j});
            i += 3, j-= 3;
        }
    }
    dbg(s);
    cout << v.size() << '\n';
    for (auto [i, j] : v)
        cout << ++i << " " << ++j << '\n';
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
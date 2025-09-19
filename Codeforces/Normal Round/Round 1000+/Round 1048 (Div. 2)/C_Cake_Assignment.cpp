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
    ll k, x;
    cin >> k >> x;
    ll total = 1;
    for (int i = 0; i <= k; i++)
        total *= 2;
    ll van = total - x, cho = x;
    dbg(total, van, cho);
    vector<ll> ans;
    while (van != cho and van != total / 2) {
        if (van > cho) {
            van -= cho;
            cho *= 2;
            ans.push_back(1);
        }
        else {
            cho -= van;
            van *= 2;
            ans.push_back(2);
        }
        dbg(van, cho);
        dbg(ans);
    }
    cout << ans.size() << '\n';
    reverse(vf(ans));
    for (auto i : ans)
        cout << i << " ";
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
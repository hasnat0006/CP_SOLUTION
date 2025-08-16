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
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<tuple<double, ll, ll>> ans;

    auto test = [&](ll wt) {
        ll water = wt * 100;
        ll suger_dissolved = min(wt * e, f - water);
        ll suger_takeC = ((ll)(suger_dissolved / c)) * c;
        ll suger_takeD = ((ll)(suger_dissolved / d)) * d;
        dbg(wt, water, suger_dissolved, suger_takeC, suger_takeD);
        if (water + suger_takeC <= f)
            ans.push_back({(1.0 * suger_takeC) / (water + suger_takeC), water, suger_takeC});
        if (water + suger_takeD <= f)
            ans.push_back({(1.0 * suger_takeD) / (water + suger_takeD), water, suger_takeD});
    };
    test(a), test(b);
    dbg(ans);
    sort(vr(ans));
    auto [aa, bb, cc] = ans.front();
    cout << bb + cc << " " << cc << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
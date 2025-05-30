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
    vector<ll> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    vector<pair<ll, ll>> range(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> range[i].first >> range[i].second;
    }

    vector<ll> last;

    ll L = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == -1)
            last.push_back(i);
        else
            L += d[i];
        while (L < range[i].first) {
            if (last.empty()) {
                cout << -1 << endl;
                return;
            }
            L++;
            d[last.back()] = 1;
            last.pop_back();
        }
        while (L + last.size() > range[i].second) {
            if (last.empty()) {
                cout << -1 << endl;
                return;
            }
            d[last.back()] = 0;
            last.pop_back();
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << max(d[i], 0LL) << " ";
    }
    cout << endl;
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
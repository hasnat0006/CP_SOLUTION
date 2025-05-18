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
#define pii pair<int, int>
const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if(n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }
    ll total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[i]) {
                total++;
            }
        }
    }
    dbg(total);
    vector<pair<ll, pii>> ans;
    for (int i = 0; i < n; i++) {
        ll rem = 0;
        for (int j = i ; j < n; j++) {
            if (v[j] < v[i])
                rem++;
            else if(v[j] > v[i])
                rem--;
            ans.push_back({total - rem, {i, j}});
        }
    }
    sort(vf(ans));
    dbg(ans);
    cout << ans[0].second.first + 1 << ' ' << ans[0].second.second + 1 << '\n';
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
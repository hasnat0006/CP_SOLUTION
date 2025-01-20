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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, vector<ll>>> v(n);
    for (int i = 0; i < n; i++) {
        vector<ll> temp(m);
        for (int j = 0; j < m; j++) {
            cin >> temp[j];
        }
        sort(vf(temp));
        v[i].first = i + 1;
        v[i].second = temp;
    }
    auto cmp = [](const pair<ll, vector<ll>> &a,
                  const pair<ll, vector<ll>> &b) {
        return (a.second.front() < b.second.front());
    };
    sort(vf(v), cmp);
    vector<ll> possible;
    vector<ll> all;
    for (int i = 0; i < n; i++) {
        possible.push_back(v[i].first);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            all.push_back(v[j].second[i]);
        }
    }
    if (!is_sorted(vf(all))) {
        cout << -1 << '\n';
        return;
    }

    for (auto i : possible)
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
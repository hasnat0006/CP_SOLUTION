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
    ll n, m;
    cin >> n >> m;
    ll arr[n][m];
    ll mx = 0;
    map<ll, vector<pair<ll, ll>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            mp[arr[i][j]].push_back({i, j});
            mx = max(mx, arr[i][j]);
        }
    }
    map<ll, ll> row, col;
    ll cntX = 0, cntY = 0, mxRow = 0, maxCol = 0;
    for (auto &[r, c] : mp[mx]) {
        row[r]++;
        if (row[r] > cntX) {
            cntX = row[r];
            mxRow = max(mxRow, r);
        }
        col[c]++;
        if (col[c] > cntY) {
            cntY = col[c];
            maxCol = max(maxCol, c);
        }
    }
    col.clear();
    row.clear();
    ll f = 0;
    for (auto &[r, c] : mp[mx]) {
        if (r == mxRow)
            continue;
        else {
            col[c]++;
        }
        if (col.size() > 1) {
            f = 1;
            break;
        }
    }
    if (f) {
        f = 0;
        for (auto &[r, c] : mp[mx]) {
            if (c == maxCol)
                continue;
            else {
                row[r]++;
            }
            if (row.size() > 1) {
                f = 1;
                break;
            }
        }
    }
    if (f)
        cout << mx << '\n';
    else
        cout << mx - 1 << '\n';
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
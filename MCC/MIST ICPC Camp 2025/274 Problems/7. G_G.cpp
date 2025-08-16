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
    ll n, m, k;
    cin >> n >> m >> k;
    char grid[505][505];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    auto isValid = [&](ll x, ll y) {
        return (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != 'x');
    };

    auto drawPossible = [&](ll x, ll y) {
        dbg(x, y, k);
        for (ll i = 0; i < k; i++) {
            ll row = x - i, col = y + i;
            ll mxRow = row + (i * 2) + 1;
            for (int j = row; j < mxRow; j++) {
                if (!isValid(j, col))
                    return false;
            }
        }
        for (int i = 1; i < k; i++) {
            ll row = x - (k - 1) + i, col = y + k - 1 + i;
            ll mxRow = row + ((k - i) * 2) - 1;
            for (int j = row; j < mxRow; j++) {
                if (!isValid(j, col))
                    return false;
            }
        }
        return true;
    };

    ll ans = 0;

    for (int i = k - 1; i < n; i++) {
        for (int j = 0; j + (2 * k - 2) < m; j++) {
            ll f = drawPossible(i, j);
            ans += f;
        }
    }
    cout << ans << '\n';
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
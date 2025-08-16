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
    ll n, m, t;
    cin >> n >> m >> t;
    vector<vector<char>> arr(n, vector<char>(m));
    pair<ll, ll> st, ed;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
                st = {i, j};
            if (arr[i][j] == 'G')
                ed = {i, j};
        }
    }
    dbg(st, ed);
    dbg(arr);
    auto isPossible = [&](ll x) {
        vector<pair<ll, ll>> xy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<ll>> vis(n, vector<ll>(m, 0)), dp(n, vector<ll>(m, -1));
        auto isValid = [&](ll i, ll j) {
            return (i >= 0 and i < n and j >= 0 and j < m and !vis[i][j]);
        };
        function<ll(ll, ll)> recursion = [&](ll i, ll j) -> ll {
            if (i == ed.first and j == ed.second)
                return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            ll tempAns = inf;
            for (auto [xx, yy] : xy) {
                if (isValid(i + xx, j + yy)) {
                    vis[i + xx][j + yy] = 1;
                    tempAns = min(tempAns, recursion(i + xx, j + yy) +
                                               (arr[i][j] == '#' ? x : 1));
                    vis[i + xx][j + yy] = 0;
                }
            }
            return dp[i][j] = tempAns;
        };
        vis[st.first][st.second] = 1;
        ll ans = recursion(st.first, st.second);
        dbg(x, ans);
        return (ans <= t);
    };

    ll l = 1, h = t * 10, ans = -1;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (isPossible(mid))
            l = mid + 1, ans = mid;
        else
            h = mid - 1;
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
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|11|2024 21:24:18            !//
//!-----------------------------------------------------!//

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

    auto isOutOfRange = [&](int x, int y, char c) {
        if (c == 'U')
            x--;
        else if (c == 'D')
            x++;
        else if (c == 'L')
            y--;
        else if (c == 'R')
            y++;
        if (x < 0 or x >= n or y < 0 or y >= m)
            return true;
        return false;
    };

    vector<vector<char>> arr(n, vector<char>(m, '?'));
    vector<vector<ll>> mark(n, vector<ll>(m, 0));
    vector<pair<ll, ll>> id;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (isOutOfRange(i, j, arr[i][j])) {
                id.push_back({i, j});
            }
        }
    }
    dbg(id);

    function<void(ll, ll)> dfs = [&](ll x, ll y) {
        if (mark[x][y])
            return;
        mark[x][y] = 1;
        // left
        if (y - 1 >= 0 and arr[x][y - 1] == 'R')
            dfs(x, y - 1);
        // right
        if (y + 1 < m and arr[x][y + 1] == 'L')
            dfs(x, y + 1);
        // up
        if (x - 1 >= 0 and arr[x - 1][y] == 'D')
            dfs(x - 1, y);
        // down
        if (x + 1 < n and arr[x + 1][y] == 'U')
            dfs(x + 1, y);
    };

    for (auto i : id) {
        dfs(i.first, i.second);
    }
    dbg(mark);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!mark[i][j]) {
                if(i > 0 and mark[i - 1][j] == 0)
                    ans++;
                else if(i + 1 < n and mark[i + 1][j] == 0)
                    ans++;
                else if(j > 0 and mark[i][j - 1] == 0)
                    ans++;
                else if(j + 1 < m and mark[i][j + 1] == 0)
                    ans++;
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
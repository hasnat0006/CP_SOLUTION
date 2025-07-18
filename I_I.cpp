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
    vector<pair<ll, ll>> path;

    auto find_path = [&](ll x) {
        vector<pair<ll, ll>> xy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<ll>> vis(n, vector<ll>(m, 0));
        auto isValid = [&](ll i, ll j) {
            return (i >= 0 and i < n and j >= 0 and j < m and !vis[i][j]);
        };
        function<long long(ll, ll)> recursion = [&](ll i, ll j) {
            if (i == ed.first and j == ed.second)
                return 1LL;
            set<pair<ll, pair<ll, ll>>> st;
            for (auto [xx, yy] : xy) {
                if (isValid(i + xx, j + yy)) {
                    vis[i + xx][j + yy] = 1;
                    ll tempCost =
                        recursion(i + xx, j + yy) + (arr[i][j] == '#' ? x : 1);
                    vis[i + xx][j + yy] = 0;
                    st.insert({tempCost, {i + xx, j + yy}});
                }
            }
            dbg(i, j, st);
            if (!st.empty()) {
                path.push_back((*st.begin()).second);
                return (*st.begin()).first;
            }
            else
                return 0LL;
        };
        vis[st.first][st.second] = 1;
        cout << recursion(st.first, st.second) << '\n';
    };
    find_path(5);
    dbg(path);

    // auto isPossible = [&](ll x) {
    //     vector<pair<ll, ll>> xy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    //     vector<vector<ll>> vis(n, vector<ll>(m, 0));
    //     auto isValid = [&](ll i, ll j) {
    //         return (i >= 0 and i < n and j >= 0 and j < m and !vis[i][j]);
    //     };
    //     function<long long(ll, ll)> recursion = [&](ll i, ll j) {
    //         if (i == ed.first and j == ed.second)
    //             return 1LL;
    //         long long tempAns = 1e18;
    //         pair<ll, ll> t;
    //         for (auto [xx, yy] : xy) {
    //             if (isValid(i + xx, j + yy)) {
    //                 vis[i + xx][j + yy] = 1;
    //                 ll cost =
    //                     recursion(i + xx, j + yy) + (arr[i][j] == '#' ? x :
    //                     1);
    //                 if (cost < tempAns) {
    //                     tempAns = cost;
    //                     t = {i + xx, j + yy};
    //                 }
    //                 vis[i + xx][j + yy] = 0;
    //             }
    //         }
    //         path.push_back(t);
    //         return tempAns;
    //     };
    //     vis[st.first][st.second] = 1;
    //     ll ans = recursion(st.first, st.second) - 1;
    //     return (ans <= t);
    // };

    // ll l = 1, h = t, ans = -1;
    // while (l <= h) {
    //     ll mid = (l + h) / 2;
    //     if (isPossible(mid))
    //         l = mid + 1, ans = mid;
    //     else
    //         h = mid - 1;
    // }
    // cout << ans << '\n';
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
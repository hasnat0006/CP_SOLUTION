#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 998244353;
const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> adj[n + 5];
    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        adj[u].push_back(v);
    }
    vector<int> parent(n + 5), level(n + 5);
    auto bfs = [&]() {
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto child : adj[t]) {
                q.push(child);
                parent[child] = t;
                level[child] = level[t] + 1;
            }
        }
        return;
    };

    bfs();
    map<int, vector<int>> mp;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        mp[level[i]].push_back(i);
        mx = max(mx, (ll)level[i]);
    }

    vector<int> dp(n + 5, 0), sum(n + 5, 0);
    function<void(int)> findAns = [&](int level) -> void {
        ll cnt = 0;
        for (auto &i : mp[level + 1])
            cnt = (cnt + dp[i]) % mod;
        for (auto &i : mp[level]) {
            ll tempAns = 1 + cnt;
            for (auto &child : adj[i])
                tempAns = (tempAns + mod - dp[child]) % mod;
            dp[i] = tempAns;
        }
        return;
    };
    for (int i = mx; i >= 1; i--)
        findAns(i);
    long long ans = 1;
    for (auto &i : mp[1])
        ans = (ans + dp[i]) % mod;
    cout << ans << "\n";
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
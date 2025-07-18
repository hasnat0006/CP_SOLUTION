#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;


void solve() {
    ll n;
    cin >> n;
    vector<ll> adj[n + 5];
    vector<ll> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        parent[i] = x;
        if (x == 0)
            continue;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    vector<vector<ll>> jump(n + 5, vector<ll>(20, -1));
    auto binaryLifting = [&]() {
        for (int i = 0; i <= n; i++) {
            jump[i][0] = parent[i];
        }

        for (int j = 1; j < 20; j++) {
            for (int i = 0; i <= n; i++) {
                int mid = jump[i][j - 1];
                if (mid != -1)
                    jump[i][j] = jump[mid][j - 1];
            }
        }
    };

    auto kthParent = [&](int u, int k) {
        for (int i = 20; i >= 0; i--) {
            if (k & (1LL << i))
                u = jump[u][i];
        }
        return u;
    };
    binaryLifting();

    ll m;
    cin >> m;
    vector<pair<ll, ll>> query[n + 1];
    for (int i = 0; i < m; i++) {
        ll u, x;
        cin >> u >> x;
        ll node = kthParent(u, x);
        query[node].push_back({x, i});
    }

    map<int, ll> mp[n + 5];
    map<int, ll> temp[n + 5];
    vector<ll> level(n + 5, 0);
    vector<ll> ans(m);

    auto merging = [&](ll c, ll u) {
        if (temp[c].size() > temp[u].size())
            swap(temp[c], temp[u]);
        for (auto &[i, val] : temp[c])
            temp[u][i] += val;
        return;
    };

    auto calculate_ans = [&](ll i) {
        for (auto &[l, id] : query[i]) {
            ans[id] = temp[i][l + level[i]];
        }
        return;
    };

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        level[u] = level[p] + 1;
        temp[u][level[u]] = 1;
        for (auto c : adj[u]) {
            if (c == p)
                continue;
            dfs(c, u);
        }
        for (auto c : adj[u]) {
            if (c == p)
                continue;
            merging(c, u);
        }
        calculate_ans(u);
    };

    for (int i = 1; i <= n; i++) {
        if (level[i] == 0) {
            dfs(i, 0);
        }
    }

    for (auto i : ans)
        cout << max(0, i - 1) << " ";
    cout << '\n';
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
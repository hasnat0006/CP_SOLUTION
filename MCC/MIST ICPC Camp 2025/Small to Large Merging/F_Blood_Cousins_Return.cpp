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
    vector<string> name(n + 1);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> name[i] >> x;
        if (x == 0) {
            st.push_back(i);
        }
            
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    ll m;
    cin >> m;
    vector<pair<ll, ll>> query[n + 1];
    for (int i = 0; i < m; i++) {
        ll u, x;
        cin >> u >> x;
        query[u].push_back({x, i});
    }

    // map<int, ll> mp[n + 5];
    map<int, set<string>> temp[n + 5];
    vector<ll> level(n + 5, 0);
    vector<ll> ans(m);

    auto merging = [&](ll c, ll u) {
        if (temp[c].size() > temp[u].size())
            swap(temp[c], temp[u]);
        for (auto &[i, val] : temp[c])
            temp[u][i].insert(val.begin(), val.end());
        return;
    };

    auto calculate_ans = [&](ll i) {
        for (auto &[l, id] : query[i]) {
            ans[id] = temp[i][l + level[i]].size();
        }
        return;
    };

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        level[u] = level[p] + 1;
        temp[u][level[u]].insert(name[u]);
        for (auto c : adj[u]) {
            if (c == p)
                continue;
            dfs(c, u);
            merging(c, u);
        }
        calculate_ans(u);
    };

    for (int i: st) {
        if (level[i] == 0) {
            dfs(i, 0);
        }
    }

    for (auto i : ans)
        cout << i << "\n";
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
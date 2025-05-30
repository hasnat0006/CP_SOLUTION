#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    map<ll, vector<ll>> adj;
    vector<ll> arr(n + 1), ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<ll, ll> visited, parent, level;

    auto bfs = [&](ll start) {
        queue<ll> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()) {
            ll k = q.front();
            q.pop();
            for (auto child : adj[k]) {
                if (!visited[child]) {
                    q.push(child);
                    visited[child] = 1;
                    parent[child] = k;
                    level[child] = level[k] + 1;
                }
            }
        }
    };

    bfs(1);
    map<ll, vector<ll>> sameLvL;
    for (int i = 1; i <= n; i++)
        sameLvL[level[i]].push_back(i);
    ans[1] = arr[1];
    map<ll, vector<ll>> temp;
    temp[1].push_back(arr[1]);
    for (auto &[lvl, nodes] : sameLvL) {
        if (lvl == 0)
            continue;
        else {
            for (auto node : nodes) {
                temp[node].push_back(arr[node]);
                ll par = parent[node];
                temp[node].push_back(arr[node] - temp[par].front());
                if(temp[par].size() > 1) {
                    temp[node].push_back(arr[node] - temp[par].back());
                }
                sort(vf(temp[node]));
                ans[node] = temp[node].back();
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
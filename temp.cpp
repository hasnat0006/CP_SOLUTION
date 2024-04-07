//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|04|2024 15:29:31            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
const int inf = 1000000000000000000;

typedef pair<int, int> pairi;
int N = 1e5 + 5;
vector<vector<pairi>> adj(N);
vector<int> dis(N, inf), parent(N);

void dijkstra(int src) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        for (auto i : adj[top.second]) {
            int v = i.first;
            int wt = i.second;
            if (dis[v] > dis[top.second] + wt) {
                dis[v] = dis[top.second] + wt;
                pq.push({dis[v], v});
                parent[v] = top.second;
            }
        }
    }
}

void solve() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    dijkstra(1);
    if (dis[n] == inf) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    int cur = n;
    ans.push_back(cur);
    while (cur != 1) {
        ans.push_back(parent[cur]);
        cur = parent[cur];
    }
    reverse(vf(ans));
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
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
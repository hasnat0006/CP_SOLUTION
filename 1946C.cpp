//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|03|2024 21:38:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

map<int, vector<int>> adj;
vector<int> visited(100005, 0);
int cut = 0;

int dfs(int node, int parent, int mid) {
    int sz = 1;
    visited[node] = 1;
    for (auto child : adj[node]) {
        if (visited[child] || child == parent)
            continue;
        sz += dfs(child, node, mid);
    }
    if(sz >= mid){
        sz = 0;
        cut++;
    }
    return sz;
}

void solve() {
    adj.clear();
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i].first >> v[i].second;
        adj[v[i].first].push_back(v[i].second);
        adj[v[i].second].push_back(v[i].first);
    }

    auto isPossible = [&](int mid) {
        cut = 0;
        fill(visited.begin(), visited.end(), 0);
        dfs(1, 0, mid);
        return cut > k;
    };

    int low = 1, high = n, result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result << endl;
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
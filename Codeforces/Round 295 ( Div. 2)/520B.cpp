//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int n, m;
vector<int> adj[50005];
vector<int> used(50005, 0);

void makeGraph(int i) {
    if (used[i] or i < 1 or i > 2 * m)
        return;
    used[i] = 1;
    adj[i].push_back(i - 1);
    makeGraph(i - 1);
    adj[i].push_back(i * 2);
    makeGraph(i * 2);
}

void solve() {
    cin >> n >> m;
    if (n > m)
        cout << n - m << endl;
    else {
        makeGraph(n);
        queue<int> q;
        // BFS
        q.push(n);
        vector<int> dist(50005, inf);
        dist[n] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : adj[v]) {
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
        cout << dist[m] << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
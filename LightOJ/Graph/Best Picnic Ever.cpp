//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL);

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

map<int, vector<int>> adj;
map<int, map<int, int>> visited, level;
vector<int> person;

void reset() {
    adj.clear();
    visited.clear();
    level.clear();
    person.clear();
}

void bfs(int person, int start) {
    queue<int> q;
    q.push(start);
    visited[person][start] = 1;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto child : adj[k]) {
            if (!visited[person][child]) {
                q.push(child);
                visited[person][child] = 1;
            }
        }
    }
}

void solve() {
    reset();
    int k, n, m, x, y;
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++)
        cin >> x, person.pb(x);
    while (m--) {
        cin >> x >> y;
        adj[x].pb(y);
    }
    for (auto i : person) {
        bfs(i, i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (auto it : person) {
            if (visited[it][i])
                c++;
        }
        if (c == person.size())
            ans++;
    }
    // debug(visited);
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case " << i << ": ", solve();
    return 0;
}
//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|11|2024 13:38:38            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
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

class Node {
   public:
    ll start, finish, prevId, cnt;
    Node() {}
    Node(ll x, ll y, ll i, ll c) { start = x, finish = y, prevId = i, cnt = c; }
    void print() {
        dbg(start, finish, prevId, cnt);
    }
};

const ll N = 10005;
vector<pair<ll, ll>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char grid[N][N];
ll n, m;

map<Node, ll> visited;
map<pair<ll, ll>, ll> level;

bool operator<(const Node a, const Node b) {
    if (a.start < b.start)
        return true;
    if (a.start == b.start and a.finish < b.finish)
        return true;
    return false;
}

bool isOk(Node a) {
    dbg(grid[a.start][a.finish]);
    dbg(visited[a]);
    a.print();
    if (visited[a] or grid[a.start][a.finish] == '#')
        return false;
    if (a.start >= 0 and a.start < n and a.finish >= 0 and a.finish < m)
        return true;
    return false;
}

void bfs(Node st) {
    queue<Node> q;
    q.push(st);
    visited[st] = 1;
    while (!q.empty()) {
        Node k = q.front();
        cout << k.start << " " << k.finish << endl;
        q.pop();
        ll id = 0;
        dbg("------------");
        for (auto [x, y] : moves) {
            if (id == k.prevId and k.cnt == 3) {
                id++;
                continue;
            }
            dbg(k.start, k.finish);
            dbg(k.start + x, k.finish + y);
            if (isOk(Node(k.start + x, k.finish + y, id,
                          id == k.prevId ? k.cnt + 1 : 1))) {
                q.push(Node(k.start + x, k.finish + y, id,
                            id == k.prevId ? k.cnt + 1 : 1));
                visited[Node(k.start + x, k.finish + y, id,
                             id == k.prevId ? k.cnt + 1 : 1)] = 1;
                level[{k.start + x, k.finish + y}] =
                    level[{k.start, k.finish}] + 1;
            }
            id++;
        }
        for(auto [node, cnt] : visited) {
            dbg(node.start, node.finish, node.prevId, node.cnt);
        }
    }
}

void solve() {
    cin >> n >> m;
    pair<ll, ll> start, sesh;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                start = {i, j};
            if (grid[i][j] == 'T')
                sesh = {i, j};
        }
    }

    vector<vector<ll>> dp(n, vector<ll> (m, - 1));

    

}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

// map<int, vector<int>> adj;
int n, m;
unordered_map<pair<int, int>, int> visited, level;
vector<pair<int, int>> alice_moves = {{1, 0}, {1, -1}, {1, 1}};
vector<pair<int, int>> bob_moves = {{-1, 0}, {-1, -1}, {-1, 1}};

bool isValid(int x, int y) {
    if (x < 1 or x > n or y < 1 or y > m)
        return false;
    if (visited[{x, y}] == 1)
        return false;
    return true;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[{x, y}] = 1;
    level[{x, y}] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (auto i : alice_moves) {
            int x1 = p.first + i.first;
            int y1 = p.second + i.second;
            if (isValid(x1, y1)) {
                visited[{x1, y1}] = 1;
                level[{x1, y1}] = level[{p.first, p.second}] + 1;
                q.push({x1, y1});
            }
        }
    }
}

void solve() {
    int x1, x2, y1, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}
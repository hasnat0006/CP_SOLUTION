//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 05|03|2024 22:01:53            !//
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

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

struct Node {
    int a, b;
};

void solve() {
    int n, T;
    cin >> n >> T;
    vector<Node> v(n);
    int mn = inf;
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].b;
    sort(vf(v), [](Node x, Node y) { return x.b < y.b; });
    int ans = 0;
    for (int i = 0; i < n; i++) {
        priority_queue<int> pq;
        int sumPQ = 0;
        for (int j = i; j < n; j++) {
            pq.push(v[j].a);
            sumPQ += v[j].a;
            int sum = sumPQ + v[j].b - v[i].b;
            while (sum > T and !pq.empty()) {
                sumPQ -= pq.top();
                sum -= pq.top();
                pq.pop();
            }
            if (sum <= T)
                ans = max(ans, (int)pq.size());
        }
    }
    cout << ans << endl;
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
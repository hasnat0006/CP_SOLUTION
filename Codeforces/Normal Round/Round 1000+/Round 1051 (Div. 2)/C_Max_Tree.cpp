#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;


void solve() {
    ll n;
    cin >> n;
    vector<tuple<ll, ll, ll, ll, ll>> edge(n - 1);
    vector<ll> cnt(n + 1);
    map<ll, ll> degree;
    vector<ll> adj[n + 5];
    for (ll i = 0; i < n - 1; i++) {
        ll u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y) {
            adj[u].push_back(v);
            degree[v]++;
        }
        else {
            adj[v].push_back(u);
            degree[u]++;
        }
    }
    
    vector<ll> ans;
    auto topo = [&]() {
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                qu.push(i);
            }
        }
        while (!qu.empty()) {
            int top = qu.front();
            qu.pop();
            ans.push_back(top);
            for (int i : adj[top]) {
                degree[i]--;
                if (degree[i] == 0) {
                    qu.push(i);
                }
            }
        }
    };

    topo();
    dbg(ans);
    vector<ll> finalAns(n);
    ll c = n;
    for(auto i : ans)
        finalAns[i - 1] = c--;
    for(auto i : finalAns)
        cout << i << ' ';
    cout << '\n';
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
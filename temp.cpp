//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "test.cpp"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

// query O(logn)
// preprocessing O(n)
struct LCA {
    vector<ll> hi, euler, first, st;
    vector<bool> visit;
    ll n;
    LCA(vector<vector<ll>> &adj, ll root = 0) {
        n = adj.size();
        hi.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visit.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        st.resize(m * 4);
        build(1, 0, m - 1);
    }
    void dfs(vector<vector<ll>> &adj, ll node, ll h = 0) {
        visit[node] = true;
        hi[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visit[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }
    void build(ll node, ll b, ll e) {
        if (b == e) {
            st[node] = euler[b];
        }
        else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = st[node << 1], r = st[node << 1 | 1];
            st[node] = (hi[l] < hi[r]) ? l : r;
        }
    }
    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return st[node];
        ll mid = (b + e) >> 1;
        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e,  L, R);
        if (left == -1)
            return right;
        if (right == -1)
            return left;
        return hi[left] < hi[right] ? left : right;
    }
    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        debug(i, v);
    }
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
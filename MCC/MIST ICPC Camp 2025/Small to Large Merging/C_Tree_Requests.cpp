
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll int

struct Node {
    map<int, bitset<30>> v;
    ll depth = 0;
    Node() {}
    void clear() { v.clear(); }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> adj[n];
    for (int i = 1; i < n; i++) {
        ll p;
        cin >> p;
        p--;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    string s;
    cin >> s;

    // set<pair<int, int>> query;
    vector<vector<pair<int, int>>> query(n);
    for (int i = 0; i < q; i++) {
        ll u, h;
        cin >> u >> h;
        u--;
        query[u].push_back({h, i});
    }

    Node st[n + 5];

    auto merging = [&](ll u, ll v) {
        for (auto [a, b] : st[v].v) {
            bitset<30> t = st[u].v[a];
            for (int i = 0; i < 30; i++) {
                t[i] = t[i] ^ b[i];
            }
            st[u].v[a] = t;
        }
        return;
    };
    bool ans[q + 5];
    auto cal_ans = [&](ll u) {
        ll my_h = st[u].depth;
        //        cout << "U H: " << u << " " << my_h << '\n';
        for (auto [h, id] : query[u]) {
            //            cout << "H id cnt: " << h  << " " << id << " " <<
            //            st[u].v[h].count() << '\n';
            if (h < my_h) {
                ans[id] = 1;
            }
            else {
                //                ans[id] = (st[u].v[h].count() <= 1);
                if (st[u].v[h].count() > 1)
                    ans[id] = 0;
                else
                    ans[id] = 1;
            }
        }
    };

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        ll dp = st[p].depth + 1;
        st[u].depth = dp;

        for (auto v : adj[u]) {
            if (v == p)
                continue;
            dfs(v, u);

            if (st[v].v.size() >= st[u].v.size())
                swap(st[u].v, st[v].v);
        }
        bitset<30> t;
        t[s[u] - 'a'] = 1;
        st[u].v[dp] = t;
        for (auto v : adj[u]) {
            if (v == p)
                continue;

            merging(u, v);
        }
        cal_ans(u);
    };
    dfs(0, 0);
    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "Yes" : "No") << '\n';
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

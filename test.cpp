//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = mod;

const ll N = 1e7 + 5;
ll isprime[N];
set<int> primes;
void sieveOfEratosthenes() {
    for (ll i = 2; i < N; i++)
        isprime[i] = 1;
    for (ll i = 4; i < N; i += 2)
        isprime[i] = 0;
    for (ll i = 3; i * i < N; i += 2) {
        if (isprime[i]) {
            for (ll j = i * i; j < N; j += i * 2)
                isprime[j] = 0;
        }
    }
    for (ll i = 2; i < N; i++)
        if (isprime[i])
            primes.insert(i);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    vector<pair<ll, ll>> store;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        store.push_back({min(u, v), max(u, v)});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> v(2 * n);
    iota(vf(v), 1);
    set<ll> st(vf(v));
    vector<ll>visited(n + 1, 0);
    dbg(st);
    map<pair<ll, ll>, ll> ans;
    function<void(ll, ll)>dfs = [&] (ll parent, ll val) -> void {
        if (visited[parent])
            return;
        visited[parent] = 1;
        for (auto it : st) {
            for (auto child : adj[parent]) {
                ll diff = abs(it - val);
                if (primes.find(diff) == primes.end()) {
                    st.erase(st.find(it));
                    dfs(child, it);
                    ans[ {min(parent, child), max(parent, child)}] = it;
                }
            }
        }
        dbg(ans);
    };
    dfs(1, 1);
    dbg(store);

    for (auto it : store) {
        cout << ans[it] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    sieveOfEratosthenes();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
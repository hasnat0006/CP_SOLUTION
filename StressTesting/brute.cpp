#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> g;
vector<ll> h;
ll n, k, ma = 0, tt = 0;

ll dfs(ll p, ll at, ll d) {
    ll s = (h[at] > k);
    ma = max(ma, s * d);
    for (ll i : g[at])
        if (i != p && dfs(at, i, d + 1))
            tt += 2, s = 1;
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    g.resize(n), h.resize(n);
    for (ll &i : h)
        cin >> i;

    for (ll i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1), g[b - 1].push_back(a - 1);
    }

    dfs(-1, 0, 0);
    cout << tt - ma << "\n";
}

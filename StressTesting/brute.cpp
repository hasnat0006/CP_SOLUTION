#include <bits/stdc++.h>
using namespace std;


#define el '\n'
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SIC_PARVIS_MAGNA ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define yes cout << "Yes" << el
#define no cout << "No" << el
#define Yes cout << "YES" << el
#define No cout << "NO" << el

#define pii pair<ll, ll>
const ll INF = 1e17;
vector<vector<pii>> graph;
vector<ll> battery;

bool dijkstra(int source, int dest, ll target) {
    vector<ll> dist(dest + 1, 0);
    ll n = dest;

    // dist is currenty battery at that node

    for (ll u = 1; u <= n; u++) {
        // onno kono node theke ekhono ekhane asha hoy nai
        if (u > 1 and dist[u] == 0)
            continue;
        dist[u] += battery[u];
        dist[u] = min(dist[u], target);
        for (auto child : graph[u]) {
            ll v = child.first;
            ll w = child.second;

            if (dist[u] >= w) {
                // multiple u theke v te asha possible tai maximum jeta sheta
                // nicchi
                dist[v] = max(dist[v], dist[u]);
            }
        }
    }

    // jodi destination visit korte pari taholei kebol destination update hoye
    // jabe
    if (dist[dest] > 0)
        return true;
    else
        return false;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    battery = vector<ll>(n + 1, 0);
    graph = vector<vector<pii>>(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> battery[i];
    ll u, v, w;

    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    ll left = 0, right = 1e9 + 10;
    ll ans = 1e15;
    while (left <= right) {
        ll mid = (left + right) / 2;

        if (dijkstra(1, n, mid)) {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else {
            left = mid + 1;
        }
    }
    if (ans == 1e15)
        ans = -1;
    cout << ans << el;
}

int main() {
    SIC_PARVIS_MAGNA;
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
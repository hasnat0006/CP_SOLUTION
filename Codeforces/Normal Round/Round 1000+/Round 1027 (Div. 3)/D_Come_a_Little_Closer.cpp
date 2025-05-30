#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    map<ll, set<ll>> X, Y;
    set<pair<ll, ll>> s;
    ll Xmin = inf, XMax = -inf, YMin = inf, YMax = -inf;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        s.insert(arr[i]);
        X[arr[i].first].insert(arr[i].second);
        Y[arr[i].second].insert(arr[i].first);
        Xmin = min(Xmin, arr[i].first);
        XMax = max(XMax, arr[i].first);
        YMin = min(YMin, arr[i].second);
        YMax = max(YMax, arr[i].second);
    }

    ll ans = inf;

    auto findAns = [&]() {
        // first and last key of map
        auto itFirstX = X.begin();
        auto itLastX = X.end();
        itLastX--;
        auto itFirstY = Y.begin();
        auto itLastY = Y.end();
        itLastY--;
        ll x1 = itFirstX->first, x2 = itLastX->first;
        ll y1 = itFirstY->first, y2 = itLastY->first;
        ll N = x2 - x1 + 1, M = y2 - y1 + 1;
        ll grid = N * M;
        // cout << "GRID: " << grid << endl;
        if (grid > n - 1)
            return grid;
        else
            return min((N + 1) * M, (N * (M + 1)));
    };
    if(X.size() == 1 && Y.size() == 1) {
        cout << 1 << endl;
        return;
    }
    for (auto [x, y] : s) {
        X[x].erase(y);
        if (X[x].empty()) {
            X.erase(x);
        }
        Y[y].erase(x);
        if (Y[y].empty()) {
            Y.erase(y);
        }
        ans = min(ans, findAns());
        X[x].insert(y);
        Y[y].insert(x);
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
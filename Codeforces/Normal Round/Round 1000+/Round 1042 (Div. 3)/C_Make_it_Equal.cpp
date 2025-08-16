#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a, b;
    set<pair<ll, ll>> stA;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
        stA.insert({x % k, i});
    }
    ll noAns = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll div = x / k;

        auto findPos = [&](ll div) {
            ll need = k * div;
            ll actualNeed = abs(x - need);
            auto id = stA.lower_bound({actualNeed, -1});
            if (id == stA.end())
                return 1;
            auto [val, j] = *id;
            if (val != actualNeed)
                return 1;
            else
                stA.erase(id);
            return 0;
        };

        ll f = findPos(div);
        if (f == 1)
            f += findPos(div + 1);
        if (f == 2) {
            noAns = 1;
        }
    }
    cout << (!noAns ? "YES" : "NO") << '\n';
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
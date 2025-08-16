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
    vector<ll> v[n];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            ll y;
            cin >> y;
            v[i].push_back(y);
        }
    }
    if (n > 2 or n == 1) {
        cout << 'S' << '\n';
        return;
    }
    while(v[0].size() and v[0].back() != 1) 
        v[0].pop_back();
    while (v[1].size() and v[1].back() != 2)
        v[1].pop_back();
    sort(vf(v[0]));
    sort(vf(v[1]));
    if((v[0].size() and v[0].front() != v[0].back()) or (v[1].size() and v[1].front() != v[1].back()))
        cout << 'N' << '\n';
    else
        cout << 'S' << '\n';
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
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
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    set<ll> st[n + 1];
    set<ll> ans;
    for (int i = 1; i <= n; i++) {
        st[i].insert(v[i]);
        ans.insert(v[i]);
        for (auto j : st[i - 1]) {
            st[i].insert(v[i] | j);
            ans.insert(v[i] | j);
        }
    }
    cout << ans.size() << '\n';
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
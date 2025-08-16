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
    queue<ll> q;
    vector<ll> v(n + 4);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        q.push(i);
        v[i] = x;
    }
    while (q.size() > 1) {
        ll t = q.front();
        q.pop();
        v[t] -= k;
        if (v[t] > 0)
            q.push(t);
    }
    cout << q.front() << '\n';
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
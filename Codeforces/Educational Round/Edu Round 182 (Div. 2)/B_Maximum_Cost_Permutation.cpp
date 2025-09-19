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
    vector<ll> v(n), done(n + 1);
    vector<ll> zero;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        done[v[i]] = 1;
        if (v[i] == 0)
            zero.push_back(i);
    }
    vector<ll> ache;
    for (int i = n; i > 0; i--) {
        if (!done[i])
            ache.push_back(i);
    }
    ll k = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0)
            v[i] = ache[k++];
    }
    ll l = 0;
    while (l < n and v[l] == l + 1)
        l++;
    ll r = n - 1;
    while (r >= 0 and v[r] == r + 1)
        r--;
    if (r >= l)
        cout << r - l + 1 << '\n';
    else
        cout << 0 << '\n';
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
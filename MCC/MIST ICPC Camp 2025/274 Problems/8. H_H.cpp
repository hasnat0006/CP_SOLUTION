#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    set<pair<ll, ll>> ans;
    auto ask = [&](ll a, ll b) {
        cout << "? " << a << " " << b << endl;
        ll x;
        cin >> x;
        return x;
    };
    for (int i = 2; i <= n; i++) {
        ans.insert({ask(1, i), i});
    }
    ll now = (*ans.rbegin()).second;
    for (int i = 1; i <= n; i++) {
        if (now != i)
            ans.insert({ask(now, i), i});
    }
    cout << "! " << (*ans.rbegin()).first << endl;
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
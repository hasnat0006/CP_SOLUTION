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
    vector<ll> a(n);
    ll l = 0, cur = 1, r = n - 1, cnt = 0;
    while (cnt < n) {
        if (cnt % 2 == 0)
            a[l++] = cur++;
        else
            a[r--] = cur++;
        cnt++;
    }
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
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
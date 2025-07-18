#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll mn = *min_element(vf(v));
    if(mn == 0) {
        cout << n << '\n';
        return;
    }
    ll i = 0, j = 0, ans = 0, p = 1;
    while (j < n) {
        p *= v[j];
        while (i < j and p > k) {
            p /= v[i];
            i++;
        }
        if(p <= k)
            ans = max(ans, j - i + 1);
        dbg(i, j, p, ans);
        j++;
    }
    cout << ans << '\n';
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
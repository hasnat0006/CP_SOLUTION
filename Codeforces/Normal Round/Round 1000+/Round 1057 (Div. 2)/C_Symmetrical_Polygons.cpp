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
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<ll> even, odd;
    map<ll, ll> sumAdd;
    ll total_sum = 0, c = 0;
    for (auto [i, cnt] : mp) {
        if (cnt == 1)
            odd.push_back(i);
        else {
            if (cnt % 2)
                odd.push_back(i);
            even.push_back(i);
            sumAdd[i] = cnt - (cnt % 2);
            total_sum += (i * sumAdd[i]);
            c += sumAdd[i];
        }
    }
    sort(vf(odd));
    sort(vf(even));
    dbg(even);
    dbg(odd);
    dbg(sumAdd);
    ll ans = 0;
    if (even.empty()) {
        cout << ans << '\n';
        return;
    }
    if (c > 2)
        ans = total_sum;
    if (odd.size() > 1) {
        for (int i = odd.size() - 2; i >= 0; i--) {
            ll b = odd[i], a = odd[i + 1];
            ll mx = max(a, even.back());
            if (total_sum + b + a - mx > mx)
                ans = max(ans, total_sum + a + b);
        }
    }
    if (!odd.empty()) {
        for (int i = odd.size() - 1; i >= 0; i--) {
            ll a = odd[i];
            ll mx = max(a, even.back());
            if (total_sum + a - mx > mx)
                ans = max(ans, total_sum + a);
        }
    }
    cout << ans << '\n';
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
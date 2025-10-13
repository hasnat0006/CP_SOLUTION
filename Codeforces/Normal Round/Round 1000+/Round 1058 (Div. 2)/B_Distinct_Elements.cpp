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
    vector<ll> ans(n + 1);
    ans[1] = 1;
    ll c = 2;
    for (int i = 2; i <= n; i++) {
        ll diff = v[i] - v[i - 1];
        if (i - diff <= 0)
            ans[i] = c++;
        else
            ans[i] = ans[i - diff];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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
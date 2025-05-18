#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    ll divByBoth = n / lcm(a, b);
    ll divByA = (n / a) - divByBoth, divByB = (n / b) - divByBoth;
    cout << divByA * p + divByB * q + divByBoth * max(p, q) << '\n';
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
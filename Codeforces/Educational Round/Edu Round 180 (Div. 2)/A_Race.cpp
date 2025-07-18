#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll a, x, y;
    cin >> a >> x >> y;
    ll X = min(x, y), Y = max(x, y);
    for (int mid = X; mid <= Y; mid++) {
        ll f = 0;
        ll B = abs(X - mid);
        ll A = abs(X - a);
        if (B < A)
            f++;
        B = abs(Y - mid);
        A = abs(Y - a);
        if (B < A)
            f++;
        if (f == 2) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a % 2 == 1 and b % 2 == 1)
        cout << a * b + 1 << '\n';
    else if (a % 2 == 0 and b % 2 == 1)
        cout << -1 << '\n';
    else if (a % 2 == 0 and b % 2 == 0) {
        cout << (a * (b / 2)) + 2 << '\n';
    }
    else {
        // a odd, b even
        if (b % 4 == 0)
            cout << (a * (b / 2)) + 2 << '\n';
        else
            cout << -1 << '\n';
    }
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
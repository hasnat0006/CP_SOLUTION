#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (n % 2 == 0) {
        if (a > b) {
            cout << (a % 2 == 0 and b % 2 == 0 ? "YES" : "NO") << '\n';
        }
        else
            cout << (b % 2 == 0 ? "YES" : "NO") << '\n';
    }
    else {
        if (a > b) {
            cout << (a % 2 == 1 and b % 2 == 1 ? "YES" : "NO") << '\n';
        }
        else
            cout << (b % 2 == 1 ? "YES" : "NO") << '\n';
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
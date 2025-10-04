#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, kx, ky, dx, dy;
    cin >> n >> kx >> ky >> dx >> dy;
    // left
    if (ky < dy and kx == dx) {
        cout << dy << '\n';
    }
    // right
    else if (ky > dy and kx == dx) {
        cout << n - dy << '\n';
    }
    // up
    else if (kx < dx and dy == ky)
        cout << dx << '\n';
    // down
    else if (kx > dx and dy == ky)
        cout << n - dx << '\n';
    // up left
    else if (kx < dx and ky < dy) {
        cout << max({dx, dy}) << '\n';
    }
    // up right
    else if (kx < dx and ky > dy) {
        cout << max({dx, n - dy}) << '\n';
    }
    // bottom left
    else if (kx > dx and ky < dy) {
        cout << max({n - dx, dy}) << '\n';
    }
    else if (kx > dx and ky > dy) {
        cout << max({n - dx, n - dy}) << '\n';
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
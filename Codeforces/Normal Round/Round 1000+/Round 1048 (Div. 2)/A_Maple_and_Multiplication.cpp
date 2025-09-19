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
    if(a > b)
        swap(a, b);
    ll g = __gcd(a, b);
    if (a == b)
        cout << 0 << '\n';
    else if (b % a == 0)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
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
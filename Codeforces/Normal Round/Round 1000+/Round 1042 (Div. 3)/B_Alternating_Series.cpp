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
    if (n % 2) {
        ll neg = 1;
        while (n--) {
            cout << (neg ? -1 : 3) << ' ';
            neg = !neg;
        }
    }
    else {
        ll neg = 1;
        n--;
        while (n--) {
            cout << (neg ? -1 : 3) << ' ';
            neg = !neg;
        }
        cout << 2;
    }
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
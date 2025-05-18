#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, x;
    cin >> n >> x;
    if (n == 1 and x == 0) {
        cout << -1 << endl;
        return;
    }
    if (x == 0) {
        cout << n + (n % 2 ? 3 : 0) << endl;
        return;
    }
    ll cnt = __builtin_popcountll(x);
    if (cnt >= n) {
        cout << x << endl;
        return;
    }
    ll finalAns = inf;
    for (int i = 1; i <= min(cnt, n); i++) {
        ll need = n - i;
        ll tempSum = x + (need % 2 ? 3 : 0) + need;
        finalAns = min(finalAns, tempSum);
    }
    cout << finalAns << endl;
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
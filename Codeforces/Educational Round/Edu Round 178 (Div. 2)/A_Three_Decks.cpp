#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if((a + b + c) % 3 != 0) {
        cout << "NO\n";
        return;
    }
    ll avg = (a + b + c) / 3;
    if(a > avg or b > avg) {
        cout << "NO\n";
        return;
    }
    ll need = avg - a + avg - b;
    if(need == (c - avg)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
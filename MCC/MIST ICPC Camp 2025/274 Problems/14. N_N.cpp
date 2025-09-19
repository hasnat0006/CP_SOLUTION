#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int countDigitOne(int n) {
    int countr = 0;
    for (int i = 1; i <= n; i *= 10) {
        int divider = i * 10;
        countr += (n / divider) * i + min(max(n % divider - i + 1, 0), i);
    }
    return countr;
}

void solve() {
    ll n;
    cin >> n;    
    cout << countDigitOne(n) << '\n';
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
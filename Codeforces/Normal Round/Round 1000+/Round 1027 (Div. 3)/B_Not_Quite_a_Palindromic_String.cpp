#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll one = 0, zero = 0;
    for (char c : s) {
        if (c == '1')
            one++;
        else
            zero++;
    }
    one = (one / 2) * 2;
    zero = (zero / 2) * 2;
    if ((one / 2) + (zero / 2) < k) {
        cout << "NO\n";
        return;
    }

    ll pairs = k * 2;
    ll diff = abs(one - zero);
    pairs -= diff;
    if (pairs < 0 or pairs % 4 != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
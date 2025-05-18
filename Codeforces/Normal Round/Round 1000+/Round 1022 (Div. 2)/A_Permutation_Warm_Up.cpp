#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;
vector<ll> ans(1000, 0);

void solve() {
    ll n;
    cin >> n;
    cout << ans[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    ans[1] = 1;
    ll inc = 1;
    for (int i = 2; i <= 500; i += 2) {
        ans[i] = ans[i - 1] + inc;
        ans[i + 1] = ans[i] + inc;
        inc++;
    }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
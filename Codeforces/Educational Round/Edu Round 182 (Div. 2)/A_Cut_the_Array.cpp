#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ll s1 = 0, s2 = 0, s3 = 0;
            for (int k = 0; k <= i; k++) {
                s1 += (v[k]);
            }
            for (int k = i + 1; k <= j; k++) {
                s2 += (v[k]);
            }
            for (int k = j + 1; k < n; k++) {
                s3 += (v[k]);
            }
            s1 %= 3, s2 %= 3, s3 %= 3;
            dbg(n, i, j, s1, s2, s3);
            if ((s1 == s2 and s2 == s3) or
                (s1 != s2 and s1 != s3 and s2 != s3)) {
                cout << i + 1 << " " << j + 1 << '\n';
                return;
            }
        }
    }
    cout << 0 << " " << 0 << '\n';
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
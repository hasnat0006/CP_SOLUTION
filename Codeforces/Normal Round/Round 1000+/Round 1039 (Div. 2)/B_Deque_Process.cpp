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
    vector<ll> v(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> v[i + 1];
    }
    string ans = "";
    ll l = 1, r = n, choto = 1;
    while (l <= r) {
        if (v[l] < v[r]) {
            if (choto == 1) {
                ans.push_back('L');
                l++;
            }
            else {
                ans.push_back('R');
                r--;
            }
            choto = !choto;
        }
        else {
            if (choto == 1) {
                ans.push_back('R');
                r--;
            }
            else {
                ans.push_back('L');
                l++;
            }
            choto = !choto;
        }
    }
    cout << ans << '\n';
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